# Connecting and Interacting with a PostgreSQL Database

This example demonstrates how to connect to a PostgreSQL database and perform a series of asynchronous operations using the Nodepp framework. This approach ensures that database queries and other I/O operations do not block your application's main thread.

```cpp
#include <nodepp/nodepp.h>
#include <postgres.h>

using namespace nodepp;

void onMain() {

    postgres_t db ("db://usr:pass@localhost:8000","dbName");

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

For more information, check out **[Nodepp-Postgres Grithub Repository](https://github.com/NodeppOficial/nodepp-postgres)**
