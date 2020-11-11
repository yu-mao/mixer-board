clc ;
clear all ;
U=5 ;  
%Resistances in the different circuits, 1 is the "first" button on the
%bread board
%Buttons
R1=220 ; 
R2=560 ;
R3=1.0*10^3;
R4= 4.7*10^3;
R1inv=0; 
R2inv=0;
R3inv=0;
R4inv= 0;
R5=1.0*10^3 ;
prompt='which buttons?';
x=input(prompt);
for ii=1:length(x) ;
                %This loop controls what buttons are in prompt
    if x(ii)==1
    R1inv=1/R1;
    end
    if x(ii)==2
    R2inv=1/R2;
    end
    if x(ii)==3
    R3inv=1/R3;
    end
    if x(ii)==4
    R4inv=1/R4;
    end
    
end
    
R=1/(R1inv+R2inv+R3inv+R4inv);
Rtot=R+R5;
I=U/Rtot  ;
U1=R*I;
Uv=U-U1  %Measurable Voltage over R5
 