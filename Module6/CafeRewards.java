import java.io.FileWriter;
import java.io.IOException;

public class CafeRewards {
    public static void main(String[] args) {
        String customerName = "Mr. Coffee";
        String email = "mister.coffee@cafe.com";
        String phoneNumber = "123-456-7890";
        String birthday = "03/14/1935";

        try {
            FileWriter writer = new FileWriter("rewards_customers.txt", true);
            writer.write("Name: " + customerName + ", Email: " + email +
                         ", Phone: " + phoneNumber + ", Birthday: " + birthday + "\n");
            writer.close();
            System.out.println("Customer data saved successfully!");
        } catch (IOException e) {
            System.out.println("Error saving customer data.");
        }
    }
}
