CREATE TABLE person (
	id INTEGER PRIMARY KEY,
	first_name TEXT,
	last_name TEXT,
	age INTEGER
);

CREATE TABLE pet (
	id INTEGER PRIMARY KEY,
	name TEXT,
	breed TEXT,
	age INTEGER,
	dead INTEGER
);

CREATE TABLE person_pet (
	person_id INTEGER,
	pet_id INTEGER
);

INSERT INTO person VALUES (0, "Braden", "Lenz", 20);
INSERT INTO person VALUES (1, "Jennifer", "Chang", 19);
INSERT INTO person VALUES (2, "Mason", "Lenz", 17);
INSERT INTO person VALUES (3, "Jordan", "Lenz", 23);
INSERT INTO person VALUES (4, "Jeff", "Lenz", 51);
INSERT INTO person VALUES (5, "Debra", "Lenz", 50);
INSERT INTO person VALUES (6, "Billy", "Bob", 42);
INSERT INTO person VALUES (7, "Jane", "Doe", 35);
INSERT INTO person VALUES (8, "John", "Doe", 35);

INSERT INTO pet VALUES	(0, "Jessie", "Doggie", 14, 0);
INSERT INTO pet VALUES  (1, "Rex", "Tyrannosaur", 100000000, 1);
INSERT INTO pet VALUES  (2, "Gigantor", "Robot", 1, 0);
INSERT INTO pet VALUES  (3, "Penis-Man", "Penis", 23, 0);

INSERT INTO person_pet VALUES (5, 0);
INSERT INTO person_pet VALUES (0, 1);
INSERT INTO person_pet VALUES (6, 2);
INSERT INTO person_pet VALUES (1, 3);



