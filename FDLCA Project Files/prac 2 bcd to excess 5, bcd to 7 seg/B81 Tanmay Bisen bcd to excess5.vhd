entity bcdtoex5 is
port(a,b,c,d: in bit;
     x,y,z,t: out bit);
end bcdtoex5;

architecture dataflow of bcdtoex5 is
begin
x<=a or b or (c and d);
y<=a or ((not b) and (not c)) or ((not b) and (not d)) or (c and b and d);
z<=c xor d;
t<= not d;
end dataflow;
