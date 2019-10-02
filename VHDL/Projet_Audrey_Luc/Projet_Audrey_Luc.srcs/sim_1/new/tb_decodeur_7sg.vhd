----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.10.2019 16:50:10
-- Design Name: 
-- Module Name: tb_decodeur_7sg - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity tb_decodeur_7sg is
--  Port ( );
end tb_decodeur_7sg;

architecture Behavioral of tb_decodeur_7sg is


component decodeur_7sg
Port ( data : in STD_LOGIC_VECTOR (3 downto 0);
           dpi : in STD_LOGIC;
           a : out STD_LOGIC;
           b : out STD_LOGIC;
           c : out STD_LOGIC;
           d : out STD_LOGIC;
           e : out STD_LOGIC;
           f : out STD_LOGIC;
           g : out STD_LOGIC;
           dpo : out STD_LOGIC);
end component;

signal s_data : std_logic_vector(3 downto 0):="0000";
signal s_dpi : std_logic :='1';
signal s_a : STD_LOGIC;
signal s_b : STD_LOGIC;
signal s_c : STD_LOGIC;
signal s_d : STD_LOGIC;
signal s_e : STD_LOGIC;
signal s_f : STD_LOGIC;
signal s_g : STD_LOGIC;
signal s_dpo : STD_LOGIC;

begin

dut : decodeur_7sg port map(
    data => s_data,
    dpi => s_dpi,
    a => s_a,
    b => s_b,
    c => s_c,
    d => s_d,
    e => s_e,
    f => s_f,
    g => s_g,
    dpo => s_dpo
    );

s_data <= "0000" after 10 ns,"0001" after 20ns, "0010" after 30ns, "0011" after 40ns, "0100" after 50ns, "0101" after 60ns,
          "0110" after 70ns, "0111" after 80ns, "1000" after 90ns, "1001"after 100ns;
s_dpi <= '0' after 25 ns, '1' after 58 ns;

end Behavioral;
