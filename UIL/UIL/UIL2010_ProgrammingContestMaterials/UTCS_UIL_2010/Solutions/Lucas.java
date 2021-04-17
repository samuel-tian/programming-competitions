
public class Lucas {
    public static void main(String[] args){
        int n0 = 2;
        int n1 = 1;
        System.out.println(2);
        System.out.println(1);
        for(int i = 2; i <= 30; i++){
            int temp = n0 + n1;
            System.out.println(temp);
            n0 = n1;
            n1 = temp;
        }
    }
}
