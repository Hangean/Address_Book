#include <iostream>
#include <string>
#include <vector>
#include "AddressBook.h"

using namespace std;

int main() {
    vector<Contact> addressBook;

    cout << "/************************************************************\n"
            << " * Prepare CSV Demo: write sample Person, Business, Vendor, *\n"
            << " * and Emergency contacts into contacts.csv for testing.    *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should create contacts.csv with valid sample contacts.\n"
            << "------------------------------------------------------------\n";

    createDemoContactsFile("contacts.csv");
    cout << "contacts.csv prepared successfully.\n\n";

    cout << "/************************************************************\n"
            << " * File To AddressBook Demo: load contacts.csv into the     *\n"
            << " * addressBook vector at program startup.                   *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should read contacts.csv and store those contacts in addressBook.\n"
            << "------------------------------------------------------------\n";

    cout << "Contacts before loading: " << addressBook.size() << endl;
    loadContactsFromFile("contacts.csv", addressBook);
    cout << "Contacts after loading: " << addressBook.size() << endl;
    listAllContacts(addressBook);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Add Person Demo: add a new Person contact using the      *\n"
            << " * addContact function and simulated console input.         *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should add Alice Adams as a Person contact.\n"
            << "------------------------------------------------------------\n";

    runAddContactWithInput(addressBook,
        "1\n"
        "Alice Adams\n"
        "555-1111\n"
        "alice@example.com\n"
        "100 Main St\n"
        "Irvine\n"
        "CA\n"
        "92612\n"
        "Family\n"
        "Important;Friend\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "Sister\n"
        "01/15\n"
        "\n"
        "Person contact added from demo input\n"
    );
    viewContactDetails(addressBook, 5);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Add Business Demo: add a new Business contact using the  *\n"
            << " * addContact function and simulated console input.         *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should add Bob Business as a Business contact.\n"
            << "------------------------------------------------------------\n";

    runAddContactWithInput(addressBook,
        "2\n"
        "Bob Business\n"
        "555-2222\n"
        "bob@techcorp.com\n"
        "200 Office Way\n"
        "Tustin\n"
        "CA\n"
        "92780\n"
        "Work\n"
        "Client;Work\n"
        "Tech Corp\n"
        "Manager\n"
        "Sales\n"
        "\n"
        "BUS-200\n"
        "\n"
        "\n"
        "\n"
        "Business contact added from demo input\n"
    );
    viewContactDetails(addressBook, 6);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Add Vendor Demo: add a new Vendor contact using the      *\n"
            << " * addContact function and simulated console input.         *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should add City Plumbing as a Vendor contact.\n"
            << "------------------------------------------------------------\n";

    runAddContactWithInput(addressBook,
        "3\n"
        "City Plumbing\n"
        "555-3333\n"
        "service@cityplumbing.com\n"
        "300 Vendor Rd\n"
        "Irvine\n"
        "CA\n"
        "92614\n"
        "Vendors\n"
        "Service;Important\n"
        "City Plumbing LLC\n"
        "\n"
        "\n"
        "Plumbing Repair\n"
        "VEN-333\n"
        "\n"
        "\n"
        "\n"
        "Vendor contact added from demo input\n"
    );
    viewContactDetails(addressBook, 7);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Add Emergency Demo: add a new Emergency contact using    *\n"
            << " * the addContact function and simulated console input.     *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should add Local Fire Department as an Emergency contact.\n"
            << "------------------------------------------------------------\n";

    runAddContactWithInput(addressBook,
        "4\n"
        "Local Fire Department\n"
        "911\n"
        "\n"
        "400 Safety Ave\n"
        "Irvine\n"
        "CA\n"
        "92618\n"
        "Emergency\n"
        "Important\n"
        "\n"
        "\n"
        "\n"
        "Emergency Services\n"
        "\n"
        "Public Safety\n"
        "\n"
        "High\n"
        "Emergency contact added from demo input with missing email\n"
    );
    viewContactDetails(addressBook, 8);
    cout << endl;

    cout << "/************************************************************\n"
            << " * List All Contacts Demo: display every contact currently  *\n"
            << " * stored in the address book.                              *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should list all loaded and added contacts.\n"
            << "------------------------------------------------------------\n";

    listAllContacts(addressBook);
    cout << endl;

    cout << "/************************************************************\n"
            << " * View Contact Demo: view the full details for one contact *\n"
            << " * by using that contact's ID number.                       *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display contact ID 7.\n"
            << "------------------------------------------------------------\n";

    viewContactDetails(addressBook, 7);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Edit Contact Demo: edit an existing contact by changing  *\n"
            << " * the name, phone number, and email address.               *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: Contact ID 5 should become Alice Anderson.\n"
            << "------------------------------------------------------------\n";

    runEditContactWithInput(addressBook, 5,
        "2\n"
        "Alice Anderson\n"
        "3\n"
        "555-9999\n"
        "4\n"
        "alice.anderson@example.com\n"
        "0\n"
    );
    viewContactDetails(addressBook, 5);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Delete Contact Demo: add a temporary contact and then    *\n"
            << " * delete it from the address book by ID.                   *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: Contact ID 99 should be deleted successfully.\n"
            << "------------------------------------------------------------\n";

    Contact deleteDemoContact(99, PERSON, "Delete Demo Contact", "555-9999", "delete@example.com");
    addressBook.push_back(deleteDemoContact);
    viewContactDetails(addressBook, 99);
    deleteContact(addressBook, 99);
    viewContactDetails(addressBook, 99);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Search By Name Demo: search for one contact by exact     *\n"
            << " * name after the edit has been completed.                  *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should find Alice Anderson.\n"
            << "------------------------------------------------------------\n";

    searchByName(addressBook, "Alice Anderson");
    cout << endl;

    cout << "/************************************************************\n"
            << " * Search By Email Demo: search for one contact by exact    *\n"
            << " * email address.                                           *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should find Bob Business.\n"
            << "------------------------------------------------------------\n";

    searchByEmail(addressBook, "bob@techcorp.com");
    cout << endl;

    cout << "/************************************************************\n"
            << " * Search By Phone Demo: search for one contact by exact    *\n"
            << " * phone number.                                            *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should find City Plumbing.\n"
            << "------------------------------------------------------------\n";

    searchByPhone(addressBook, "555-3333");
    cout << endl;

    cout << "/************************************************************\n"
            << " * Filter By Type Demo: display only contacts that match    *\n"
            << " * the Vendor contact type.                                 *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display Vendor contacts only.\n"
            << "------------------------------------------------------------\n";

    filterByContactType(addressBook, VENDOR);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Filter By City Demo: display only contacts located in    *\n"
            << " * the city of Irvine.                                      *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display Irvine contacts only.\n"
            << "------------------------------------------------------------\n";

    filterByCity(addressBook, "Irvine");
    cout << endl;

    cout << "/************************************************************\n"
            << " * Filter By Tag Demo: display only contacts that have the  *\n"
            << " * Important tag.                                           *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display contacts tagged Important.\n"
            << "------------------------------------------------------------\n";

    filterByTag(addressBook, "Important");
    cout << endl;

    cout << "/************************************************************\n"
            << " * Assign Group Demo: assign contact ID 7 to the Vendors    *\n"
            << " * group and display the updated contact.                   *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: Contact ID 7 should show group Vendors.\n"
            << "------------------------------------------------------------\n";

    assignGroup(addressBook, 7, "Vendors");
    viewContactDetails(addressBook, 7);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Add Tag Demo: add the VIP tag to contact ID 6 and show   *\n"
            << " * the updated contact details.                             *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: Contact ID 6 should include the VIP tag.\n"
            << "------------------------------------------------------------\n";

    addTagToContact(addressBook, 6, "VIP");
    viewContactDetails(addressBook, 6);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Remove Tag Demo: remove the Client tag from contact ID 6 *\n"
            << " * and show the updated contact details.                    *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: Contact ID 6 should no longer show the Client tag.\n"
            << "------------------------------------------------------------\n";

    removeTagFromContact(addressBook, 6, "Client");
    viewContactDetails(addressBook, 6);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Report By Type Demo: list all contacts grouped by their  *\n"
            << " * contact type.                                            *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should show Person, Business, Vendor, and Emergency sections.\n"
            << "------------------------------------------------------------\n";

    listContactsByType(addressBook);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Missing Info Report Demo: display contacts that are      *\n"
            << " * missing either email or phone information.               *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: Emergency contacts should appear because email is missing.\n"
            << "------------------------------------------------------------\n";

    showContactsMissingEmailOrPhone(addressBook);
    cout << endl;

    cout << "/************************************************************\n"
            << " * Group Summary Report Demo: count and display how many    *\n"
            << " * contacts are assigned to each group.                     *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display group names and counts.\n"
            << "------------------------------------------------------------\n";

    displayGroupSummaries(addressBook);
    cout << endl;

    cout << "/************************************************************\n"
            << " * AddressBook To File Demo: write all current contacts     *\n"
            << " * from addressBook into saved_contacts.csv.                *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should export the addressBook vector to saved_contacts.csv.\n"
            << "------------------------------------------------------------\n";

    saveContactsToFile(addressBook, "saved_contacts.csv");
    cout << "saved_contacts.csv written successfully.\n\n";

    cout << "/************************************************************\n"
            << " * Saved File Reload Demo: load saved_contacts.csv into a   *\n"
            << " * second vector to prove that saving and loading both work. *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should reload saved_contacts.csv and list the contacts.\n"
            << "------------------------------------------------------------\n";

    vector<Contact> loadedAddressBook;
    cout << "Contacts before loading saved file: " << loadedAddressBook.size() << endl;
    loadContactsFromFile("saved_contacts.csv", loadedAddressBook);
    cout << "Contacts after loading saved file: " << loadedAddressBook.size() << endl;
    listAllContacts(loadedAddressBook);

    return 0;
}
