# dough
A simple money (dough) tracker built using CMake, Qt, and SQLite.

The application allows users to track their expenses and incomes with various details:
- Title
- Date
- Amount
- Description
- Category (only applicable to expenses)

## Features
- Add, track, remove expenses and incomes
- SQLite database integration to store and manage records

## Planned Features
- User authentication
- Visualizations and Analytics
- Export data to CSV or .db
- Import data from CSV or .db
- Multi currency support

## Getting Started

### Installing Qt Creator
1. Download the Qt online installer from the [Qt website](https://www.qt.io/download)
2. Run the installer and follow the instructions to install Qt Creator and the required Qt libraries (make sure to include Qt6 and the necessary modules).
3. During installation, you can choose the components you need. Ensure that Qt Creator and the Qt6 Core and SQL modules are selected.

### Cloning the repository
Follow these steps to clone this repository:
1. Ensure you have [Git](https://git-scm.com/) installed on your computer
2. Open Git Bash (or similar terminal)
3. Navigate to your desired directory:
```bash
cd path/to/your/directory
```
4. Clone the repositry:
```bash
git clone https://github.com/notexploiting/dough
```
5. Change to the repository directory:
```bash
cd dough
```

### Opening the project in Qt Creator
1. Open Qt Creator
2. Click on 'File' -> 'Open File or Project...'
3. Navigate to the directory where you cloned the repository and select 'CMakeLists.txt'
4. Qt Creator will configure the project. Follow any prompts to set up the necessary kits and configurations
5. You'll see the project in Qt Creator's project explorer once the configuration is complete
6. You can now build and run the project from within Qt Creator by hitting the green play button or using the appropriate build and run commands


## Releases
Coming soon!

## Dependencies
- Qt6 (Core, SQL modules)
- CMake (version 3.5 or higher)
- SQLite (included with Qt)

## Contributing
Please open an issue or submit a pull request for any changes or improvements.

## Contact
For any questions or suggestions, please contact [notexploiting@gmail.com](mailto:notexploiting@gmail.com)
