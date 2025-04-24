Complete the provided skeleton C++ code as detailed in the tasks below which relates to a system that manages hospital patient records. It must dynamically create and manage Patient objects and track their details in the hospital system. You are provided with the following files:

main.cpp – contains code for testing and developing your implementation.
Hospital.h (read-only) – contains the declarations of the Hospital class.
Hospital.cpp – you will write your C++ code for the implementation of the Hospital class in this file.
Patient.h and Patient.cpp (read-only) – contain the declaration and implementation of the Patient class.
Class Details

Hospital Class: you will implement this class as described in the tasks below. This class maintains a private record of dynamically, allocated Patient objects using a std::vector<Patient*> patients

Patient Class: this is provided for you. It has the following data members:

std::string name – Name of the patient.
std::string ailment – A description of the patient's ailment.
int treatmentDays – Number of days required for treatment.
objectCount - A static data member that tracks the total number of Patient objects created and deleted.
Your completed code will be tested with unit tests that dynamically create objects of the Hospital class, that contain dynamically allocated objects of the Patient class. Examples are provided in main.cpp as follows:

Hospital* hospital = new Hospital();
hospital->patients.push_back(new Patient("Julie", "Fever", 3));
hospital->patients.push_back(new Patient("Sheryl", "Appendicitis", 5));
hospital->patients.push_back(new Patient("Michael", "Severe Fever", 7)); 
and the count of dynamically allocated Patient objects, i.e. the value of ObjectCount, will be: 3

Task 1: Discharge a Patient

Implement the following Hospital class member function:

void discharge_patient(const std::string& name);
The function has the following input parameter:

name: Name of the patient to discharge.
Function Details: the function should:

find the Patient object in the the vector patients, using the name. NOTE you can assume that the name is unique and that it exists in the vector patients
deallocate the Patient object.
remove the pointer to the Patient object from the vector patients
Example: for the following

Hospital* hospital = new Hospital();
hospital->patients.push_back(new Patient("Julie", "Fever", 3));
hospital->patients.push_back(new Patient("Sheryl", "Appendicitis", 5));
hospital->patients.push_back(new Patient("Michael", "Severe Fever", 7)); 
hospital->discharge_patient("Michael");  
your function should:

deallocate the Patient object with name "Michael"
Note that this will automatically decrement by 1 the value of Patient::objectCount
remove the pointer to the Patient with name "Michael" from the vector patients
After the discharge_patient function, the value of objectCount should be: 0

Task 2: Destructor

Complete the following destructor:

Hospital::~Hospital()
This should:

deallocate all dynamically allocated Patient objects that are pointed to in the vector patients of the Hospital object
empty the vector patients of the Hospital object
Example: for the following:

Hospital* hospital = new Hospital();
hospital->patients.push_back(new Patient("Julie", "Fever", 3));
hospital->patients.push_back(new Patient("Sheryl", "Appendicitis", 5));
hospital->patients.push_back(new Patient("Michael", "Severe Fever", 7)); 
delete hospital;
the value of objectCount after delete hospital should be: 0



#include <iostream>
#include <string>
#include "Hospital.h"
#include "Patient.h"
#include "utilities.h" // Provides print_patients which you can use to test your code (see below)

int main()
{
   /***********************************************************************
    * This code is provided as a starting point for development and testing
    * Please modify the code below as you develop your program.
    * *********************************************************************/

   Hospital* hospital = new Hospital();
   hospital->patients.push_back(new Patient("Julie", "Fever", 3));
   hospital->patients.push_back(new Patient("Sheryl", "Appendicitis", 5));
   hospital->patients.push_back(new Patient("Michael", "Severe Fever", 7)); 
   print_patients(hospital);
   std::cout << "Count of Patient objects: " << Patient::objectCount << "\n";
 
   hospital->discharge_patient("Michael");  
   print_patients(hospital);
   std::cout << "Count of Patient objects: " << Patient::objectCount << "\n";
   
   delete hospital;
   std::cout << "Count of Patient objects: " << Patient::objectCount << "\n";
   
   return EXIT_SUCCESS;
}



#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Patient.h"
#include <vector>
#include <string>

class Hospital {
public:
   Hospital();
   ~Hospital();

   void discharge_patient(const std::string& name);
   int get_total_treatment_days();

   std::vector<Patient*> patients; 
};

#endif


#include "Hospital.h"

Hospital::Hospital() {} // Constructor - provided for you

/************************************************************************
   Task 1 - discharge_patient                                        
*************************************************************************/
void Hospital::discharge_patient(const std::string& name) 
{
   for (Patient*& patient : patients) {
      if (patient->name == name) {
         delete this->name;

         // remove found patient right in here

         // Patient::objectCount -= 1;
         break;

      }
   }

   patients.erase(std::remove(patients.begin(), patients.end(), nullptr), patients.end()); // for
}

/************************************************************************
   Task 2 - Destructor for Patient                                        
*************************************************************************/
Hospital::~Hospital()
{
   // Your code goes here
   Patient::objectCount = 0;

   patients.empty();

   for (Patient*& patient : patients) {
      
      delete this;
   }


}


#ifndef PATIENT_H
#define PATIENT_H

#include <string>

class Patient {
public:
    static int objectCount; 

    Patient(const std::string& name, const std::string& ailment, int treatmentDays);
    ~Patient();

    std::string name;
    std::string ailment;
    int treatmentDays;
};

#endif



#include "Patient.h"
 
int Patient::objectCount = 0;

Patient::Patient(const std::string& name, const std::string& ailment, int treatmentDays)
    : name(name), ailment(ailment), treatmentDays(treatmentDays) {
    ++objectCount;
}

Patient::~Patient() {
    --objectCount;
}

