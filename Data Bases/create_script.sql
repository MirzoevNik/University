USE mirzoevnik
GO
CREATE TABLE car (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_car PRIMARY KEY,
	vin VARCHAR(17) NOT NULL,
	id_model INTEGER NOT NULL,
	id_color INTEGER NOT NULL,
	id_type_car INTEGER NOT NULL
)
GO
CREATE TABLE car_mark (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_car_mark PRIMARY KEY,
	mark_code VARCHAR(100) NOT NULL UNIQUE
)
GO
CREATE TABLE car_model (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_car_model PRIMARY KEY,
	id_mark INTEGER NOT NULL,
	model_code VARCHAR(100) NOT NULL UNIQUE
)
GO
CREATE TABLE color (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_color PRIMARY KEY,
	color_code VARCHAR(100) NOT NULL UNIQUE
)
GO
CREATE TABLE person (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_person PRIMARY KEY,
	surname VARCHAR(100) NOT NULL,
	name VARCHAR(100) NOT NULL,
	patronymic VARCHAR(100) NOT NULL,
	birthday DATETIME NOT NULL,
	birthplace INTEGER NOT NULL
)
GO
CREATE TABLE country (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_country PRIMARY KEY,
	country_code VARCHAR(100) NOT NULL UNIQUE
)
GO
CREATE TABLE city (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_city PRIMARY KEY,
	id_country INTEGER NOT NULL,
	city_code VARCHAR(100) NOT NULL
)
GO
CREATE TABLE street (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_street PRIMARY KEY,
	id_city INTEGER NOT NULL,
	street_code VARCHAR(100) NOT NULL
)
GO
CREATE TABLE driver (
	id_person INT NOT NULL CONSTRAINT pk_driver PRIMARY KEY,
	experience FLOAT NULL
)
GO
CREATE TABLE client (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_client PRIMARY KEY,
	id_person INTEGER,
	id_company INTEGER,
	inn VARCHAR(11) NOT NULL UNIQUE,
	phone VARCHAR(11)
)
GO
CREATE TABLE company_car (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_company_car PRIMARY KEY,
	id_car INTEGER NOT NULL,
	id_company INTEGER NOT NULL
)
GO
CREATE TABLE location (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_location PRIMARY KEY,
	id_street INTEGER NOT NULL,
	house_number VARCHAR(10) NOT NULL,
	id_index INTEGER NOT NULL
)
GO
CREATE TABLE using_car (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_using_car PRIMARY KEY,
	id_company_car INTEGER NOT NULL,
	id_driver INTEGER NOT NULL,
	start_time DATETIME NOT NULL,
	finish_time DATETIME NOT NULL
)
GO
CREATE TABLE company (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_company PRIMARY KEY,
	name VARCHAR(200) NOT NULL,
	id_location INTEGER NOT NULL,
	cars_count INTEGER NULL
)
GO
CREATE TABLE index_table (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_index_table PRIMARY KEY,
	index_code VARCHAR(8) NOT NULL UNIQUE
)
GO
CREATE TABLE product (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_product PRIMARY KEY,
	name VARCHAR(200) NOT NULL,
	id_color INTEGER NOT NULL,
	product_weight FLOAT NOT NULL,
	id_type_product INTEGER NOT NULL
)
GO
CREATE TABLE category_license (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_category_license PRIMARY KEY,
	category_code VARCHAR(3) NOT NULL UNIQUE
)
GO
CREATE TABLE driver_category_license (
	id_driver INTEGER NOT NULL,
	id_category_license INTEGER NOT NULL,
	date_receipt DATETIME NOT NULL
)
GO
CREATE TABLE order_table (
	id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_order_table PRIMARY KEY,
	id_using_car INTEGER NOT NULL,
	id_client INTEGER NOT NULL,
	start_time DATETIME NOT NULL,
	finish_time DATETIME NOT NULL,
	start_location INTEGER NOT NULL,
	finish_location INTEGER NOT NULL,
	price FLOAT NOT NULL
)
GO
CREATE TABLE order_product (
	id_order INTEGER NOT NULL,
	id_product INTEGER NOT NULL
)
GO
CREATE TABLE type_car (
  id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_type_car PRIMARY KEY,
  type_code VARCHAR(100)
)
GO
CREATE TABLE type_product (
  id INT IDENTITY(1, 1) NOT NULL CONSTRAINT pk_type_product PRIMARY KEY,
  type_code VARCHAR(100)
)
GO
CREATE TABLE type_car_type_product (
	id_type_car INTEGER NOT NULL,
	id_type_product INTEGER NOT NULL
)
GO
CREATE TABLE type_car_category_license (
	id_type_car INTEGER NOT NULL,
	id_category_license INTEGER NOT NULL
)
GO

ALTER TABLE car WITH CHECK ADD CONSTRAINT car_fk0 FOREIGN KEY (id_model) REFERENCES car_model(id)
ON UPDATE CASCADE
GO
ALTER TABLE car CHECK CONSTRAINT car_fk0
GO
ALTER TABLE car WITH CHECK ADD CONSTRAINT car_fk1 FOREIGN KEY (id_color) REFERENCES color(id)
ON UPDATE CASCADE
GO
ALTER TABLE car CHECK CONSTRAINT car_fk1
GO
ALTER TABLE car WITH CHECK ADD CONSTRAINT car_fk2 FOREIGN KEY (id_type_car) REFERENCES type_car(id)
ON UPDATE CASCADE
GO
ALTER TABLE car CHECK CONSTRAINT car_fk2
GO


ALTER TABLE car_model WITH CHECK ADD CONSTRAINT car_model_fk0 FOREIGN KEY (id_mark) REFERENCES car_mark(id)
ON UPDATE CASCADE
GO
ALTER TABLE car_model CHECK CONSTRAINT car_model_fk0
GO


ALTER TABLE person WITH CHECK ADD CONSTRAINT person_fk0 FOREIGN KEY (birthplace) REFERENCES city(id)
ON UPDATE CASCADE
GO
ALTER TABLE person CHECK CONSTRAINT person_fk0
GO


ALTER TABLE city WITH CHECK ADD CONSTRAINT city_fk0 FOREIGN KEY (id_country) REFERENCES country(id)
ON UPDATE CASCADE
GO
ALTER TABLE city CHECK CONSTRAINT city_fk0
GO

ALTER TABLE street WITH CHECK ADD CONSTRAINT street_fk0 FOREIGN KEY (id_city) REFERENCES city(id)
ON UPDATE CASCADE
GO
ALTER TABLE street CHECK CONSTRAINT street_fk0
GO

ALTER TABLE driver WITH CHECK ADD CONSTRAINT driver_fk0 FOREIGN KEY (id_person) REFERENCES person(id)
GO
ALTER TABLE driver CHECK CONSTRAINT driver_fk0
GO

ALTER TABLE client WITH CHECK ADD CONSTRAINT client_fk0 FOREIGN KEY (id_person) REFERENCES person(id)
ON UPDATE CASCADE
GO
ALTER TABLE client CHECK CONSTRAINT client_fk0
GO
ALTER TABLE client WITH CHECK ADD CONSTRAINT client_fk1 FOREIGN KEY (id_company) REFERENCES company(id)
ON UPDATE CASCADE
GO
ALTER TABLE client CHECK CONSTRAINT client_fk1
GO

ALTER TABLE company_car WITH CHECK ADD CONSTRAINT company_car_fk0 FOREIGN KEY (id_car) REFERENCES car(id)
ON UPDATE CASCADE
GO
ALTER TABLE company_car CHECK CONSTRAINT company_car_fk0
GO
ALTER TABLE company_car WITH CHECK ADD CONSTRAINT company_car_fk1 FOREIGN KEY (id_company) REFERENCES company(id)
ON UPDATE CASCADE
GO
ALTER TABLE company_car CHECK CONSTRAINT company_car_fk1
GO

ALTER TABLE location WITH CHECK ADD CONSTRAINT location_fk0 FOREIGN KEY (id_street) REFERENCES street(id)
ON UPDATE CASCADE
GO
ALTER TABLE location CHECK CONSTRAINT location_fk0
GO
ALTER TABLE location WITH CHECK ADD CONSTRAINT location_fk1 FOREIGN KEY (id_index) REFERENCES index_table(id)
ON UPDATE CASCADE
GO
ALTER TABLE location CHECK CONSTRAINT location_fk1
GO

ALTER TABLE using_car WITH CHECK ADD CONSTRAINT using_car_fk0 FOREIGN KEY (id_company_car) REFERENCES company_car(id)
ON UPDATE CASCADE
GO
ALTER TABLE using_car CHECK CONSTRAINT using_car_fk0
GO
ALTER TABLE using_car WITH CHECK ADD CONSTRAINT using_car_fk1 FOREIGN KEY (id_driver) REFERENCES driver(id_person)
ON UPDATE CASCADE
GO
ALTER TABLE using_car CHECK CONSTRAINT using_car_fk1
GO

ALTER TABLE company WITH CHECK ADD CONSTRAINT company_fk0 FOREIGN KEY (id_location) REFERENCES location(id)
GO
ALTER TABLE company CHECK CONSTRAINT company_fk0
GO


ALTER TABLE product WITH CHECK ADD CONSTRAINT product_fk0 FOREIGN KEY (id_color) REFERENCES color(id)
ON UPDATE CASCADE
GO
ALTER TABLE product CHECK CONSTRAINT product_fk0
GO
ALTER TABLE product WITH CHECK ADD CONSTRAINT product_fk1 FOREIGN KEY (id_type_product) REFERENCES type_product(id)
GO
ALTER TABLE product CHECK CONSTRAINT product_fk1
GO

ALTER TABLE driver_category_license WITH CHECK ADD CONSTRAINT driver_category_license_fk0 FOREIGN KEY (id_driver) REFERENCES driver(id_person)
ON UPDATE CASCADE
GO
ALTER TABLE driver_category_license CHECK CONSTRAINT driver_category_license_fk0
GO
ALTER TABLE driver_category_license WITH CHECK ADD CONSTRAINT driver_category_license_fk1 FOREIGN KEY (id_category_license) REFERENCES category_license(id)
ON UPDATE CASCADE
GO
ALTER TABLE driver_category_license CHECK CONSTRAINT driver_category_license_fk1
GO

ALTER TABLE order_table WITH CHECK ADD CONSTRAINT order_fk0 FOREIGN KEY (id_using_car) REFERENCES using_car(id)
ON UPDATE CASCADE
GO
ALTER TABLE order_table CHECK CONSTRAINT order_fk0
GO
ALTER TABLE order_table WITH CHECK ADD CONSTRAINT order_fk1 FOREIGN KEY (start_location) REFERENCES location(id)
GO
ALTER TABLE order_table CHECK CONSTRAINT order_fk1
GO
ALTER TABLE order_table WITH CHECK ADD CONSTRAINT order_fk2 FOREIGN KEY (finish_location) REFERENCES location(id)
GO
ALTER TABLE order_table CHECK CONSTRAINT order_fk2
GO
ALTER TABLE order_table WITH CHECK ADD CONSTRAINT order_fk3 FOREIGN KEY (id_client) REFERENCES client(id)
GO
ALTER TABLE order_table CHECK CONSTRAINT order_fk3
GO

ALTER TABLE order_product WITH CHECK ADD CONSTRAINT order_product_fk0 FOREIGN KEY (id_order) REFERENCES order_table(id)
GO
ALTER TABLE order_product CHECK CONSTRAINT order_product_fk0
GO
ALTER TABLE order_product WITH CHECK ADD CONSTRAINT order_product_fk1 FOREIGN KEY (id_product) REFERENCES product(id)
GO
ALTER TABLE order_product CHECK CONSTRAINT order_product_fk1
GO

ALTER TABLE type_car_type_product WITH CHECK ADD CONSTRAINT type_car_type_product_fk0 FOREIGN KEY (id_type_car) REFERENCES type_car(id)
ON UPDATE CASCADE
GO
ALTER TABLE type_car_type_product CHECK CONSTRAINT type_car_type_product_fk0
GO
ALTER TABLE type_car_type_product WITH CHECK ADD CONSTRAINT type_car_type_product_fk1 FOREIGN KEY (id_type_product) REFERENCES type_product(id)
GO
ALTER TABLE type_car_type_product CHECK CONSTRAINT type_car_type_product_fk1
GO

ALTER TABLE type_car_category_license WITH CHECK ADD CONSTRAINT type_car_category_license_fk0 FOREIGN KEY (id_type_car) REFERENCES type_car(id)
ON UPDATE CASCADE
GO
ALTER TABLE type_car_category_license CHECK CONSTRAINT type_car_category_license_fk0
GO
ALTER TABLE type_car_category_license WITH CHECK ADD CONSTRAINT type_car_category_license_fk1 FOREIGN KEY (id_category_license) REFERENCES category_license(id)
GO
ALTER TABLE type_car_category_license CHECK CONSTRAINT type_car_category_license_fk1
GO