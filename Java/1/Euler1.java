import java.util.HashSet;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;

/**
 *
 * Author       :   Collen Roller
 *
 * Euler1       :   Project Euler Project 1 on a new account, attempting to solve a large series of euler problems
 *              :   in different languages
 *
 * Problem      :   if we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
 *                  The sum of these multiples is 23. Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Approach     :   Definition of a natural number A natural number is a number that occurs commonly and obviously
 *              :   in nature. As such, it is a whole, non-negative number. The set of natural numbers, denoted N,
 *              :   can be defined in either of two ways: N = {0, 1, 2, 3, ...}
 *
 *              :   From this definition, we can infer natural number are definied by Integers and not Doubles...
 *              :   numbers with a "whole" value
 *
 *              :   For the example problem we further infer, that the natural numbers below 10 lye within the set below
 *              :   N(10) = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
 *
 *              :   The multiples of three create a subset of N(10), M(3,N(10)) = {3,6,9}
 *              :   Similarly for 5, M(5,N(10)) = {5}
 *
 *              :   This program will take in input of a maximum of natural number, and compute the set of multiples
 *              :   of x1 and x2 below max
 *
 */

public class Euler1 {

    private static ArrayList<Integer> x;
    private static int max;

    public static void main(String [] args) {
        //Parse Arguments
        if(args.length < 2) {
            System.out.println(getUsageStatement());
            System.exit(1);
        }

        max = Integer.parseInt(args[0]);
        x = new ArrayList<Integer>();
        for(int i = 1; i < args.length; i++){
            x.add(Integer.parseInt(args[i]));
        }

        Set<Integer> resultsSet = computeMultiples();
        Iterator iter = resultsSet.iterator();
        int resultSum = 0;
        while (iter.hasNext()) {
            resultSum += (int)iter.next();
        }
        System.out.println("Number of items in the final set : " + resultsSet.size());
        System.out.println("Sum of final set : " + resultSum);

    }

    /**
     *
     * @purpose         :   Computes the set of multiples
     *
     * @return          :   set of computed multiples
     */
    public static Set<Integer> computeMultiples(){

        Set<Integer> set = new HashSet<Integer>();

        //Iterate Through All Of The Mutilple Numbers
        for(int i = 0; i < x.size(); i++) {
            int currentHighest = x.get(i);
            while(currentHighest < max){
                set.add(currentHighest);
                currentHighest += x.get(i);
            }
        }
        return set;
    }

    /**
     *
     * @purpose         :   Return the usage statement for the program
     *
     * @return          :   usage statement
     */
    public static String getUsageStatement(){
        String usage = "" +
                "\nProject Euler 1, Usage........" +
                "\n<maxium> <multiple1, multiple2, multiple3.....mulipleN>" +
                "\nProblem  :   if we list all the natural numbers below 10 that are multiples of 3 or 5" +
                "\nwe get 3, 5, 6 and 9 The sum of these multiples is 23. " +
                "\nFind the sum of all the multiples of 3 or 5 below 1000.";
                return usage;
    }

}
