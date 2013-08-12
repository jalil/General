create table Stock (
	sector_id
	sector_id integer primary key,
	sector text
);

insert into product values (0, "#2 Pencils -- 10 pack", 2.99, 0.99, 1);
insert into product values (1, "#3 Pencils -- 5 pack", 4.99, 1.99, 1);

insert into customer values (0, "Braden", "Lenz", "lenzbradens@gmail.com", 55555555555, 20);
insert into customer values (1, "John", "Smith", "anotherjohnsmith@jsmith.com", 1111111111, 35);
insert into customer values (2, "Jane", "Doe", "idontknowwhoIam@whoami.com", 22222222222, 35);
insert into customer values (3, "John", "Doe", "iamprettysureiamanonymous@whoami.com", 3333333333, 35);
insert into customer values (4, "Billy", "Bob", "billybob@hillbilly.com", 4444444444, 50);
insert into customer values (5, "Barbara", "Ann", "imnotfromthebeachboys@gmail.com", 6666666666, 25);

insert into sales values (0, 0, 0, 5);
insert into sales values (1, 1, 2, 2);
insert into sales values (2, 0, 0, 10);
insert into sales values (3, 1, 1, 1);
insert into sales values (4, 1, 3, 4);
insert into sales values (5, 0, 4, 100);
insert into sales values (6, 0, 5, 40);

update customer SET first_name = "Jon"
	where first_name = "John";	
