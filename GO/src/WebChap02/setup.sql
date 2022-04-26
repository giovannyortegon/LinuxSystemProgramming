create table users (
	id			serial primary key,
	uuid		varchar(64) not null unique,
	name		varchar(255),
	email		varchar(255) not null unique,
	password	varchar(255) not null,
	create_at	timestamp not null
);

create table session (
	id			serial primary key,
	uuid		varchar()
);
