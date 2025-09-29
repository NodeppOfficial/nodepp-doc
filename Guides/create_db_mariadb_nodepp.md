# Connecting and Interacting with a MariaDB Database

This example demonstrates how to connect to and interact with a MariaDB database using the Nodepp framework. By leveraging Nodepp's asynchronous capabilities, you can perform database operations such as creating tables, inserting data, and querying records without blocking the main event loop.

```cpp
#include <nodepp/nodepp.h>
#include <mariadb.h>

using namespace nodepp;

void onMain() {

    // 1. Establish the database connection.
    // Replace "usr" and "pass" with your database credentials.
    // The standard MariaDB port is 3306.
    mariadb_t db("db://usr:pass@localhost:3306", "dbName");

    // 2. Create a new table named 'COMPANY'.
    db.exec(R"(
        CREATE TABLE IF NOT EXISTS COMPANY(
        ID INT PRIMARY KEY     NOT NULL,
        NAME           TEXT    NOT NULL,
        AGE            INT     NOT NULL,
        ADDRESS        CHAR(50),
        SALARY         REAL );
    )", [=]() {

        // 3. Insert multiple records into the 'COMPANY' table.
        // This is done inside the callback to ensure the table is created first.
        console::log("Table 'COMPANY' created or already exists.");

        db.exec(R"(
            INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY)
            VALUES (1, 'Paul', 32, 'California', 20000.00);
        )");
        db.exec(R"(
            INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY)
            VALUES (2, 'John', 25, 'Texas', 15000.00);
        )");
        db.exec(R"(
            INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY)
            VALUES (3, 'Mary', 29, 'New York', 25000.00);
        )");
        db.exec(R"(
            INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY)
            VALUES (4, 'Frank', 35, 'Florida', 30000.00);
        )");

        // 4. Query all records from the 'COMPANY' table.
        // The callback function will be executed for each row returned.
        db.exec("SELECT * from COMPANY", [](sql_item_t args) {
            console::log("--- New Record ---");
            for( auto& key: args.keys() ) {
                console::log( key, "->", args[key] );
            }
        });
    });
}
```

For more information, check out **[Nodepp-MariaDB Grithub Repository](https://github.com/NodeppOficial/nodepp-mariadb)**
