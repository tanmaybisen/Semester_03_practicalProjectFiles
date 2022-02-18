entity nornand is
port(a,b: in bit;
     x,y:out bit);
end nornand;

architecture dataflow of nornand is
begin
x<=a nor b;
y<=((a nand a) nand (b nand b)) nand ((a nand a) nand (b nand b));
end dataflow;
