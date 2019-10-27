clear all
clc
close all
cd D:/pooooo/
load euler.txt;

tf = 1.5;
pas = 0.01;
alpha = 0;
t = euler(:,1)
fexacte = (alpha-1/3)*exp(-3*t)-t+1/3;

%plot(t,fexacte)
hold on
plot(t,euler(:,2))
