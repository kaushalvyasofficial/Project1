import java.util.ArrayList;
import java.util.HashMap;
import java.io.*;

public class ContactBook {
    private Contact[] contactsArray;  // Using Array
    private ArrayList<Contact> contactsArrayList;  // Using ArrayList
    private HashMap<String, Contact> contactsHashMap;  // Using HashMap

    public ContactBook(int capacity) {
        contactsArray = new Contact[capacity];
        contactsArrayList = new ArrayList<>();
        contactsHashMap = new HashMap<>();
    }

    // Add contact
    public void addContact(Contact contact) {
        for(int i = 0; i < 10; i++)
            if(contactsArray[i] == null) {
                contactsArray[i] = contact;
                break;
            }
        contactsArrayList.add(contact);
        contactsHashMap.put(contact.getName(), contact);
    }

    // Search for a contact by name
    public Contact searchByNameArray(String name) {
        for (Contact contact : contactsArray) 
            if (contact != null && contact.getName().equals(name)) 
                return contact;
        return null;
    }

    public Contact searchByNameArrayList(String name) {
        for (Contact contact : contactsArrayList) 
            if (contact.getName().equals(name)) 
                return contact;
        return null;
    }

    public Contact searchByNameHashMap(String name) {
        return contactsHashMap.get(name);
    }

    // Display all contacts
    public void displayAllContactsArray() {
        for (Contact contact : contactsArray)
            if (contact != null)
                System.out.println(contact);
    }

    public void displayAllContactsArrayList() {
        for (Contact contact : contactsArrayList)
            System.out.println(contact);
    }

    public void displayAllContactsHashMap() {
        for (Contact contact : contactsHashMap.values())
            System.out.println(contact);
    }

    public static void main(String[] args) throws IOException {
        ContactBook contactBook = new ContactBook(10);

        // Adding contacts
        System.out.println("How many contacts do you want to add?");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int ct = Integer.parseInt(br.readLine());

        while(ct-- != 0) {
            System.out.println("Enter Name: ");
            String name = br.readLine();
            System.out.println("Enter Phone Num: ");
            String ph = br.readLine();
            System.out.println();
            contactBook.addContact(new Contact(name, ph));
        }


        // Searching for contacts
        System.out.println("Search by name (Array): " + contactBook.searchByNameArray("Kishore"));
        System.out.println("Search by name (ArrayList): " + contactBook.searchByNameArrayList("Kaushal"));
        System.out.println("Search by name (HashMap): " + contactBook.searchByNameHashMap("Himanshu"));


        // Displaying all contacts
        System.out.println("\nContacts (Array):");
        contactBook.displayAllContactsArray();

        System.out.println("\nContacts (ArrayList):");
        contactBook.displayAllContactsArrayList();

        System.out.println("\nContacts (HashMap):");
        contactBook.displayAllContactsHashMap();
    }
}