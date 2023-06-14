public class demo {
    public static void main(String[] args) {
        String st = "ict     dept    mit      manipal";

        String s[] = st.split(" ?");

        for (int i = 0; i < s.length; i++)
            System.out.println(s[i]);

    }
}
