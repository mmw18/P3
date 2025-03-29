public class OrderTotal {
    public static void main(String[] args) {
        double subtotal = 28.50;
        double taxRate = 0.08;

        // Using local scope for temp variables
        double taxAmount = calculateTax(subtotal, taxRate);
        double total = subtotal + taxAmount;

        System.out.println("Total order amount: $" + total);
    }
    // Method only has access to values passed to it
    private static double calculateTax(double amount, double rate) {
        return amount * rate;
    }
}
