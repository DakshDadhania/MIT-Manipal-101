x1=int(input("x1 "))
y1=int(input("y1 "))
z1=int(input("z1 "))
c1=int(input("c1 "))
x2=int(input("x2 "))
y2=int(input("y2 "))
z2=int(input("z2 "))
c2=int(input("c2 "))
x3=int(input("x3 "))
y3=int(input("y3 "))
z3=int(input("z3 "))
c3=int(input("c3 "))
it=int(input("iterations "))

x=0.0
y=0.0
z=0.0
for temp in range(it):

    x=(c1-y1*y-z1*z)/x1
    y=(c2-x2*x-z2*z)/y2
    z=(c3-y3*y-x3*x)/z3

    print("x=",round(x,4), "y=",round(y,4), "z=",round(z,4) )
