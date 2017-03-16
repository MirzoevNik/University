USE mirzoevnik
GO

-- INSERT
INSERT car_mark(mark_code)
VALUES('Volkswagen')
INSERT car_mark(mark_code)
VALUES('Lada')
GO
INSERT car_model(id_mark, model_code)
VALUES(1, 'Polo')
INSERT car_model(id_mark, model_code)
VALUES(2, 'Priora')
INSERT car_model(id_mark, model_code)
VALUES(2, 'Vesta')
GO
INSERT color(color_code)
VALUES('Black')
INSERT color(color_code)
VALUES('Blue')
INSERT color(color_code)
VALUES('White')
INSERT color(color_code)
VALUES('Grey')
INSERT color(color_code)
VALUES('Red')
INSERT color(color_code)
VALUES('Yellow')
GO
INSERT type_car(type_code)
VALUES('passenger')
GO
INSERT car(vin, id_model, id_color, id_type_car)
VALUES('4USBT53544LT26841', 1, 1, 1)
GO
INSERT country(country_code)
VALUES('Russia')
GO
INSERT city(id_country, city_code)
VALUES(1, 'Saratov')
GO
INSERT street(id_city, street_code)
VALUES(1, 'Volskaya')
GO
INSERT index_table(index_code)
VALUES('420034')
GO
INSERT index_table(index_code)
VALUES('420036')
GO
INSERT location(id_street, house_number, id_index)
VALUES(1, '15A', 1)
GO
INSERT location(id_street, house_number, id_index)
VALUES(1, '1', 2)
GO
INSERT person(surname, name, patronymic, birthday, birthplace)
VALUES('Ivanov', 'Ivan', 'Ivanovich', '03.01.1995', 1)
GO
INSERT person(surname, name, patronymic, birthday, birthplace)
VALUES('Ivanov2', 'Ivan2', 'Ivanovich2', '03.01.1995', 1)
GO
INSERT driver(id_person, experience)
VALUES(1, 2.5)
GO
INSERT category_license(category_code)
VALUES('A')
GO
INSERT category_license(category_code)
VALUES('B')
GO
INSERT category_license(category_code)
VALUES('C')
GO
INSERT category_license(category_code)
VALUES('D')
GO
INSERT type_car_category_license(id_type_car, id_category_license)
VALUES (1, 2)
GO
INSERT driver_category_license(id_driver, id_category_license, date_receipt)
VALUES(1, 2, '08.22.2015')
GO
INSERT company(name, id_location, cars_count)
VALUES('New Cool Company', 1, 1)
GO
INSERT client(id_company, inn, phone)
VALUES(1, '6449013711', '89994447733')
GO
INSERT client(id_person, inn, phone)
VALUES(2, '6449013712', '89994447833')
GO
INSERT company_car(id_car, id_company)
VALUES(1, 1)
GO
INSERT using_car(id_company_car, id_driver, start_time, finish_time)
VALUES(1, 1, '01.12.2017', '02.20.2017')
GO
INSERT type_product(type_code)
VALUES('lightweight')
GO
INSERT product(name, id_color, product_weight, id_type_product)
VALUES('Cheese', 6, 0.5, 1)
GO
INSERT type_car_type_product(id_type_car, id_type_product)
VALUES(1, 1)
GO
INSERT order_table(id_using_car, id_client, start_time, finish_time, start_location, finish_location, price)
VALUES(1, 1, '01.28.2017', '02.02.2017', 1, 2, 350)
GO
INSERT order_product(id_order, id_product)
VALUES(1, 1)
GO

-- DELETE
/*DELETE color WHERE color_code LIKE 'White'
GO*/