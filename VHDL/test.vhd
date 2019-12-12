----------------------
-- Bascule D --
-----------------------

-- Entity
entity basculeD is
	port(	D : in std_logic;
			clk : in std_logic;
			rst, preset : in std_logic;
			Q : out std_logic);
end basculeD;

-- Architecture concurrent
architecture concurrent of basculeD is

begin

Q<=	'0' when rst='1' else
	'1' when preset='1' else
	D when (clk'event and clk='1');
end concurrent;

-- Architecture process
architecture proc of basculeD is
begin

process(rst,preset,clk)
begin
if rst='1' then
	Q<='0';
	elsif preset='1' then
	Q<='1';
	elsif (clk'event and clk='1') then
	Q<=D;
end if;
end process;

end proc;



-- Test Bench
ENTITY tb_basculeD IS
END tb_basculeD;

ARCHITECTURE behavior OF tb_basculeD IS

    COMPONENT basculeD
    PORT(
         D : IN  std_logic;
         clk : IN  std_logic;
         rst : IN  std_logic;
         preset : IN  std_logic;
         Q : OUT  std_logic
        );
    END COMPONENT;

   signal s_D : std_logic := '0';
   signal s_clk : std_logic := '0';
   signal s_rst : std_logic := '0';
   signal s_preset : std_logic := '0';
   signal s_Q : std_logic;

   constant clk_period : time := 20 ns;

BEGIN
   bascule1: basculeD PORT MAP (
          D => s_D,
          clk => s_clk,
          rst => s_rst,
          preset => s_preset,
          Q => s_Q
        );

   clk_process :process
   begin
		s_clk <= '0';
		wait for clk_period/2;
		s_clk <= '1';
		wait for clk_period/2;
   end process;

   s_rst <='1', '0' after 171 ns,'1' after 353 ns;
s_preset <= '0', '1' after 131 ns, '0' after 221 ns, '1' after 301 ns;
s_D <= '0', '1' after 251 ns;

END;


-------------------------
-- Registre --
------------------------

entity registre is
port( E : in std_logic_vector(7 downto 0);
		clk : in std_logic;
		load : in std_logic;
		rst : in std_logic;
		S_in : in std_logic;
		S_out: out std_logic);
end registre;

architecture v1 of registre is
signal reg : std_logic_vector(7 downto 0);

begin

process(rst,clk)
begin
if rst='1' then
	reg<= (others =>'0'); -- reg<="00000000";
	elsif rising_edge(clk) then
	if load='1' then
		reg <= E;
		else reg(7 downto 1) <= reg(6 downto 0);
		reg(0) <= S_in;
	end if;
end if;
end process;

S_out <= reg(7);

end v1;

--------------------------------
-- 2 regsitres    --
--------------------------------
entity deux_registres is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           load : in  STD_LOGIC;
           S_in : in  STD_LOGIC;
           S_out : out  STD_LOGIC;
           E1 : in  STD_LOGIC_VECTOR (7 downto 0);
			  E2 : in  STD_LOGIC_VECTOR (7 downto 0));
end deux_registres;

architecture Behavioral of deux_registres is
component registre
port(E : in std_logic_vector(7 downto 0);
		clk : in std_logic;
		load : in std_logic;
		rst : in std_logic;
		S_in : in std_logic;
		S_out: out std_logic);
end component;
signal S_int : std_logic;

begin

reg1: registre port map(
			E => E1,
			clk => clk,
			load => load,
			rst => rst,
			S_in => S_in,
			S_out => S_int);


reg2 : registre port map(
			E => E2,
			clk => clk,
			load => load,
			rst => rst,
			S_in => S_int,
			S_out => S_out);

end Behavioral;

--------------------------------
-- Compteur --
----------------------------------
-- Module compteur
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity compteur is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
			  ce : in  STD_LOGIC;
           pg : out  STD_LOGIC;
           cpt : out  unsigned (3 downto 0));
end compteur;

architecture Behavioral of compteur is
signal s_cpt : unsigned(3 downto 0);
begin

cpt <= s_cpt;

process(rst,clk)
begin

if rst='1' then
		s_cpt <= "0000"; --pg<='0';
		elsif rising_edge(clk) then
		if ce='0' then
			s_cpt<=s_cpt;
			elsif s_cpt="1001" then
			s_cpt <="0000";
			--pg<='1'; ATTENTION cette solution ne marche pas! pg=1 quand cpt=0;
			else s_cpt <= s_cpt + 1; --pg <='0';
		end if;
end if;
end process;

pg <= '1' when s_cpt="1001" else '0';

end Behavioral;

-- Testbench compteur
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY tb_compteur IS
END tb_compteur;

ARCHITECTURE behavior OF tb_compteur IS

    COMPONENT compteur
    PORT(
         clk : IN  std_logic;
         rst : IN  std_logic;
         ce : IN  std_logic;
         pg : OUT  std_logic;
         cpt : OUT  unsigned(3 downto 0)
        );
    END COMPONENT;

   signal clk : std_logic := '0';
   signal rst : std_logic := '0';
   signal ce : std_logic := '0';

   signal pg : std_logic;
   signal cpt : unsigned(3 downto 0);

   constant clk_period : time := 20 ns;

BEGIN
   uut: compteur PORT MAP (
          clk => clk,
          rst => rst,
          ce => ce,
          pg => pg,
          cpt => cpt
        );

   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;

 rst <='1', '0' after 171 ns;
 ce <='1', '0' after 511 ns;

END;


----------------------------
-- Serrure cod�e --
--------------------------

entity serrure is
    Port ( rst : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           ouverture : out  STD_LOGIC;
           alarme : out  STD_LOGIC);
end serrure;

architecture Behavioral of serrure is
type etat is (init, inter, ouvert,alerte);
signal etatp,etatf : etat;
begin

blocF : process(etatp,a,b)
begin
case etatp is
	when init => if a='1' and b='1' then
						etatf <= inter;
						elsif a='1' and b='0' then
						etatf<=alerte;
						else etatf<=init;
					end if;
	when inter => if a='0' and b='0' then
						etatf <= init;
						elsif a='1' and b='0' then
						etatf<=ouvert;
						elsif a='0' and b='1' then
						etatf<=alerte;
						else etatf<=inter;
					end if;

	when alerte => if a='0' and b='0' then
							etatf<=init;
							else etatf<=alerte;
						end if;

	when ouvert => if a='0' and b='0' then
							etatf<=init;
							else etatf<=ouvert;
						end if;

	when others => etatf<=init;
end case;
end process;


blocM: process(rst,clk)
begin
if rst='1' then
	etatp<=init;
	elsif rising_edge(clk) then
	etatp<=etatf;
end if;
end process;

-- bloc G1
alarme <='1' when etatp=alerte else '0';
ouverture <='1' when etatp=ouvert else '0';

-- bloc G alternate
blocG: process(etatp)
begin
case etatp is
	when alerte => ouverture<='0'; alarme<='1';
	when ouvert => ouverture<='1'; alarme<='0';
	when others => ouverture<='0'; alarme<='0';
end case;
end process;
