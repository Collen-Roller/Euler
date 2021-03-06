/**
 *
 * Author       :   Collen Roller
 *
 * Euler2       :   Each new term in the Fibonacci sequence is generated by adding the previous two terms.
 *              :   By starting with 1 and 2, the first 10 terms will be:
 *
 *              :   1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 *              :   By considering the terms in the Fibonacci sequence whose values do not exceed four million,
 *              :   find the sum of the even-valued terms.
 *
 */

public class Euler2 {

    public static void main(String [] args){

        //Parse Arguments
        if(args.length < 1) {
            System.out.println(getUsageStatement());
            System.exit(1);
        }

        int max = Integer.parseInt(args[0]);

        int current = 1;
        int temp;
        int previous = 0;

        int totalFibNumbers = 0;
        int numberOfEvenFibNumbers = 0;
        int sumOfEvenFibNumbers = 0;


        while(current < max){
            totalFibNumbers++;
            if(current % 2 == 0){
                numberOfEvenFibNumbers++;
                sumOfEvenFibNumbers += current;
            }

            temp = current+previous;
            previous = current;
            current = temp;
        }

        System.out.println("Total number of fib numbers under " + max + " is : " + totalFibNumbers);
        System.out.println("Number of Even Fib Numbers under " + max + " is : " + numberOfEvenFibNumbers);
        System.out.println("Sum of the even fib numbbers under " + max + " is : " + sumOfEvenFibNumbers);

    }

    /**
     *
     * @purpose         :   Return the usage statement for the program
     *
     * @return          :   usage statement
     */
    public static String getUsageStatement() {
        String usage = "" +
                "\nProject Euler 2, Usage......." +
                "\n<maximum> "+
                "\nProblem  :   Each new term in the Fibonacci sequence is generated by adding the previous two terms." +
                "\nBy starting with 1 and 2, the first 10 terms will be: " +
                "\n1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ..." +
                "\nBy considering the terms in the Fibonacci sequence whose values do not exceed four million," +
                "\nfind the sum of the even-valued terms.";
        return usage;
    }
}
