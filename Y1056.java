import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		int sum = 0;
		Scanner in = new Scanner(System.in);
		int number = in.nextInt();
		int [] array = new int[number];
		for(int i = 0; i<number ; ++i){
			array[i] = in.nextInt();
		}
		for(int i = 0; i<array.length;++i){
			sum+=array[i];
		}
		sum = 11*(number-1)*sum;
		System.out.println(sum);
	}
}