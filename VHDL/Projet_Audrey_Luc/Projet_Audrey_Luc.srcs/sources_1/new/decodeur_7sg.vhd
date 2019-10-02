----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02.10.2019 16:32:01
-- Design Name: 
-- Module Name: decodeur_7sg - Behavioral
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity decodeur_7sg is
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
end decodeur_7sg;

architecture Behavioral of decodeur_7sg is

signal s_reponse : STD_LOGIC_VECTOR(6 downto 0);
begin
process(data, s_reponse)
begin
if data = "0000" then
    s_reponse <= "0000001";
elsif data = "0001" then
    s_reponse <= "1001111";
elsif data = "0010" then
    s_reponse <= "0010010";
elsif data = "0011" then
    s_reponse <= "0000110";
elsif data = "0100" then
    s_reponse <= "1001100";
elsif data ="0101" then
    s_reponse <= "0100100";
elsif data = "0110" then
    s_reponse <= "0100000";
elsif data="0111" then
    s_reponse <= "0001111";
elsif data="1000" then 
    s_reponse <= "0000000";
elsif data="1001" then
    s_reponse <= "0000100";
    else
    s_reponse <= "1111111";
end if;
end process;
dpo <= dpi;
a <= s_reponse(6);
b <= s_reponse(5);
c <= s_reponse(4);
d <= s_reponse(3);
e <= s_reponse(2);
f <= s_reponse(1);
g <= s_reponse(0);

end Behavioral;
