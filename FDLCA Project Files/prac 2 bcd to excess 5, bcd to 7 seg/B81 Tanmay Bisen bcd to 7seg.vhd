entity sevenseg is
port(A,B,C,D: in bit;
     a1,b1,c1,d1,e,f,g: out bit);
end sevenseg;

architecture dataflow of sevenseg is
begin
a1<=A or C or (B and D) or ((not B) and (not D));
b1<=(not B) or ((not C) and (not D)) or (C and D);
c1<=B or (not C) or D;
d1<=((C) and (not D)) or ((not B) and (not D)) or ((not B) and C) or ((B) and (not C) and (D)) or A;
e<=((not B) and (not D)) or ((C) and (not D));
f<=A or ((not C) and (not D)) or ((B) and (not C)) or ((B) and (not D));
g<=((not B) and (C)) or ((C) and (not D)) or ((B) and (not C)) or A;
end dataflow;
