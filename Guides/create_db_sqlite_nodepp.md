# Connecting and Interacting with an SQLite Database

This example demonstrates how to work with a SQLite database using the Nodepp framework. Since SQLite is a file-based database, this approach is perfect for local data storage in desktop or embedded applications. The code showcases how to create a table, insert records, and perform a query.

```cpp
#include <nodepp/nodepp.h>
#include <sqlite.h>

using namespace nodepp;

void onMain() {

    sqlite_t db ("myDB.db");

    db.exec(R"(
        CREATE TABLE COMPANY(
        ID INT PRIMARY KEY     NOT NULL,
        NAME           TEXT    NOT NULL,
        AGE            INT     NOT NULL,
        ADDRESS        CHAR(50),
        SALARY         REAL );
    )");

    db.exec(R"(
        INSERT INTO COMPANY ( ID, NAME, AGE, ADDRESS, SALARY )
        VALUES (1, 'Paul', 32, 'California', 20000.00 );
    )");

    db.exec(R"(
        INSERT INTO COMPANY ( ID, NAME, AGE, ADDRESS, SALARY )
        VALUES (2, 'John', 32, 'California', 20000.00 );
    )");

    db.exec(R"(
        INSERT INTO COMPANY ( ID, NAME, AGE, ADDRESS, SALARY )
        VALUES (3, 'Mery', 32, 'California', 20000.00 );
    )");

    db.exec(R"(
        INSERT INTO COMPANY ( ID, NAME, AGE, ADDRESS, SALARY )
        VALUES (4, 'Pipi', 32, 'California', 20000.00 );
    )");

    db.exec("SELECT * from COMPANY",[]( sql_item_t args ){
        for( auto &x: args.keys() ){
             console::log( x, "->", args[x] );
        }
    });

}
```

For more information, check out **[Nodepp-SQLite Grithub Repository](https://github.com/NodeppOficial/nodepp-sqlite)**
