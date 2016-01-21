import java.math.BigInteger;
import java.util.ArrayList;

/**
 *
 * Author       :   Collen Roller
 *
 * Euler3       :   The prime factors of 13195 are 5, 7, 13 and 29.
 *
 *              :   What is the largest prime factor of the number 600851475143 ?
 *
 *
 */

public class Euler3 {

    public static void main(String [] args){
        //Parse Arguments
        if(args.length < 1) {
            System.out.println(getUsageStatement());
            System.exit(1);
        }
        try {
            long max = Long.parseLong(args[0]);
            long largestPrimeFactor = computeResult(max);
            System.out.println("Largest Prime Factor of " + max + " is : " + largestPrimeFactor);

        }catch(Exception e){
            e.printStackTrace();
            System.err.println(args[0] + " is not a valid integer");
            System.out.println(getUsageStatement());
            System.exit(1);
        }
    }

    public static long computeResult(long max){
        long currentMax = 0;
        for(long i = 2; i <= max/2; i++){
            if(max % i == 0){
                System.out.println("Factor Found : " + i);
                if(isPrime(i)){
                    System.out.println("Apparently : " + i + " is a prime number");
                    currentMax = i;
                }
            }
        }
        return currentMax;
    }

    public static boolean isPrime(long max){
        boolean prime = true;
        for(long i = 2; i < max; i++){
            if(max % i == 0){
                return false;
            }
        }
        return prime;
    }

    /**
     *
     * @purpose         :   Return the usage statement for the program
     *
     * @return          :   usage statement
     */
    public static String getUsageStatement() {
        String usage = "" +
                "\nProject Euler 3, Usage......." +
                "\n<maximum number> "+
                "\nProblem  :   The prime factors of 13195 are 5, 7, 13 and 29" +
                "\nWhat is the largest prime factor of the number of the input number?\n";
        return usage;
    }

}
