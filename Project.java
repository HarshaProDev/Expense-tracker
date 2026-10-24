
import java.util.Scanner;

class newexpense
{
    String date;
    String category;
    double expenses;

    static double total = 0;

    newexpense(String d, String c, double e)
    {
        date = d;
        category = c;
        expenses = e;
        total += expenses;
    }

    void displayhistory()
    {
        System.out.println("Date: " + date);
        System.out.println("Category: " + category);
        System.out.println("Amount: " + expenses);
        System.out.println("----------------------");
    }

    static void showtotal()
    {
        System.out.println("Total Expenses: " + total);
    }
}

class project1
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        newexpense expensesList[] = new newexpense[100];

        int count = 0;
        int choice;

        do
        {
            System.out.println("\n---- Expense Tracker ----");
            System.out.println("1. Add Expenses");
            System.out.println("2. View Expense History");
            System.out.println("3. Show Total Expenses");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");

            choice = sc.nextInt();
            sc.nextLine();

            switch(choice)
            {
                case 1:
                {
                    if(count == expensesList.length)
                    {
                        System.out.println("Expense storage is full.");
                        break;
                    }

                    System.out.print("Enter Date (DD-MM-YYYY): ");
                    String date = sc.nextLine();

                    System.out.println("Select Category:");
                    System.out.println("1. Food");
                    System.out.println("2. Transport");
                    System.out.println("3. Shopping");
                    System.out.print("Enter category choice: ");

                    int catChoice = sc.nextInt();
                    sc.nextLine();

                    String category="NULL";

                    switch(catChoice)
                    {
                        case 1:
                            category = "Food";
                            break;
                        case 2:
                            category = "Transport";
                            break;
                        case 3:
                            category = "Shopping";
                            break;
                        default:
                            System.out.println("Invalid Category");
                            break;
                    }

                    if(catChoice < 1 || catChoice > 3)
                    {
                        break;
                    }

                    System.out.print("Enter Amount: ");
                    double amount = sc.nextDouble();
                    sc.nextLine();

                    if(amount < 0)
                    {
                        System.out.println("Amount cannot be negative.");
                        break;
                    }

                    expensesList[count] =
                        new newexpense(date, category, amount);

                    count++;

                    System.out.println("Expense added successfully!");
                    break;
                }

                case 2:
                {
                    if(count == 0)
                    {
                        System.out.println("No expenses recorded.");
                    }
                    else
                    {
                        for(int i = 0; i < count; i++)
                        {
                            expensesList[i].displayhistory();
                        }
                    }
                    break;
                }

                case 3:
                {
                    newexpense.showtotal();
                    break;
                }

                case 4:
                {
                    System.out.println("Exiting Expense Tracker...");
                    break;
                }

                default:
                    System.out.println("Invalid choice. Try again.");
            }

        } while(choice != 4);

        sc.close();
    }
}
