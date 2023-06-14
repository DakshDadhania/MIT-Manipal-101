package Additional;

class example2 {
    int num;
    // Static class
    static class X {
    static String str="Inside Class X";
    int num=99;
    }

    public static void main(String args[])
    {
    example2.X obj = new example2.X();
    System.out.println("Value of num="+obj.num);
    }
}