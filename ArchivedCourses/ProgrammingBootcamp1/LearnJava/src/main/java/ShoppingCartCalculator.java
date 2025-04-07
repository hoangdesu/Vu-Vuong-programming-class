import java.util.Scanner;


public class ShoppingCartCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("What is the customer's name? ");
        String customerName = sc.nextLine();
        System.out.print("What is the sales tax rate (%)? ");
        double salesTaxRate = sc.nextDouble();
        System.out.print("How many items are being purchased? ");
        int numOfItems = sc.nextInt();

        double subtotal = 0;
        for (int i = 1; i <= numOfItems; i++) {
            System.out.print("Enter item#" + i + " price : ");
            double price = sc.nextDouble();
            System.out.print("Enter item#" + i + " quantity : ");
            int quantity = sc.nextInt();
            subtotal = price * quantity;
        }

        printBill(customerName, subtotal, salesTaxRate);
    }

    //     Method to calculate total and print the customer's bill
    public static void printBill(String customerName, double beforeTaxTotal, double taxRate) {
        double saleTax = beforeTaxTotal * (taxRate / 100);
        double total = beforeTaxTotal + saleTax;

        System.out.printf("Billing Statement for %s:\n", customerName);
        System.out.printf("Subtotal: $%.2f\n", beforeTaxTotal);
        System.out.printf("Sales Tax: $%.2f\n", saleTax);
        System.out.printf("Total: $%.2f\n", total);
    }
}