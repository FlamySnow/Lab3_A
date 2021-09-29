# Printed Circuit Board

>This program describes a printed circuit board and provides ways to interact with it.

## How PCB is described

PCB in this implementation is an array of fixed length of contacts.
Contacts have coordinates, type (input or output) and number of connected contact, if it exists.

# What can you do with this program:

* You can add contacts to your PCB, but number of contacts is limited;
* You can get current information about your PCB;
* Establish connect between 2 contacts, but each contact is available to only one connection and connected contacts must be of different types.
* Get numbers of contacts that have the same type;
* Get length of the track between 2 contacts.
