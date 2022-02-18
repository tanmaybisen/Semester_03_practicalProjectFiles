entity nandnor is
port(a,b: in bit;
     x,y:out bit);
end nandnor;

architecture dataflow of nandnor is
begin
x<=a nand b;
y<=((a nor a) nor (b nor b)) nor ((a nor a) nor (b nor b));
end dataflow;
