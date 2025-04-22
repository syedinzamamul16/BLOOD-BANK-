# BLOOD-BANK
Blood Bank Management System
This C-based Blood Bank Management System is designed to assist the Red Crescent Blood Center, Dhaka-1212 in maintaining a well-organized donor database and managing real-time blood stock information. It supports up to 1000 donors and allows an admin to add, search, update, and record blood donations while ensuring efficient file-based data persistence between sessions.
Each Donor Record Includes:
#Personal Information: Name, Blood Type, Contact Information.
#Availability: Indicate if the donor is currently available for donation.
Features:
Add Donor:
1. Collect and store new donor details.
2. Name, Blood Group (A+, A-, B+, B-, AB+, AB-, O+, O-), Contact Info, and Availability (1/0).
3. Data is stored in an array of struct Donor, which tracks each donor's profile.
Search Donor by Blood Type:
1. Find all matching donors by entering a blood group.
2. Displays name, contact info, and availability of matching entries.
Record Blood Donation:
1. Record the donation of a specific blood type and update the blood stock array accordingly.
2. Ensures the validity of blood type entered before recording.
View Blood Stock:
1.Displays the current units available for each blood type.
2.Data is updated every time a donation is recorded.

Save Data to File:
1.Saves all donor records and blood stock data to a text file named blood_donation_data.txt.
2.Ensures persistent data storage between sessions using fprintf().
Load Data on Startup:
1.Reads existing donor records and blood stock levels from the blood_donation_data.txt file during startup.
2.Ensures that previously saved data is restored into memory before operations begin.
Core Functionalities:
i. Struct Usage: A Donor struct holds all key donor details.
ii. Array: donors[1000] stores up to 1000 donor records.
iii. File Handling: Uses text-based files to read/write donor and stock data.
iv. Functions:
              a) addDonor() – Adds a new donor.
              b) searchByBloodType() – Looks up donors by blood group.
              c) recordDonation() – Updates stock after a donation.
              d) viewBloodStock() – Displays current inventory.
              e) saveDataToFile() – Saves current state to a file.
              f) loadDataFromFile() – Loads saved state from a file.
              g) password() – Authenticates user access before showing the main menu.
Complexities and Challenges:
1. Input Handling Issues: Use of gets() and scanf() together can cause issues.
2. Security Flaw: gets() is vulnerable, should be replaced by fgets(). 
3. File Format Consistency: Suggest using binary files for future versions.
Future Development
Secure authentication system - Implement multi-user login with roles (admin, staff, viewer).
Integrate donation history tracking, showing how often a donor donates and when they last donated.
Blood expiry date tracking - Track how long blood units have been stored, automatically remove expired units (e.g., after 42 days).
Implement SMS/email notifications to contact available donors in case of emergencies.
Use binary files for secure and structured data saving/loading, replacing the plain-text format.
Abridgement:
This application offers a user-friendly interface for medical staff to manage a blood donor network and blood stock effectively. It ensures that donor information is up-to-date, blood donations are accurately recorded, and all data is preserved between program sessions. It is a reliable solution for streamlining blood center operations and maintaining life saving stock levels efficiently.
