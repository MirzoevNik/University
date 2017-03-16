USE mirzoevnik
GO

CREATE TRIGGER trg_person_insert_update
	ON person FOR INSERT, UPDATE
	AS IF UPDATE(birthday)
BEGIN
	IF (SELECT p.birthday
		FROM inserted p) >= GETDATE()
	BEGIN
		ROLLBACK TRANSACTION
		PRINT 'Error! Birthday is incorrect!'
	END
	ELSE
		PRINT 'Successful operation!'
END
GO

CREATE TRIGGER trg_driver_category_license_insert_update
	ON driver_category_license FOR INSERT, UPDATE
	AS IF UPDATE(date_receipt)
BEGIN
	IF (SELECT dcl.date_receipt
		FROM inserted dcl) >= GETDATE()
	BEGIN
		ROLLBACK TRANSACTION
		PRINT 'Error! Date of receipt is incorrect!'
	END
	ELSE
		PRINT 'Successful operation!'
END
GO

CREATE TRIGGER trg_order_insert_update
	ON order_table FOR INSERT, UPDATE
	AS
BEGIN
	DECLARE @startTime DATETIME
	DECLARE @finishTime DATETIME

	SELECT @startTime = (SELECT ot.start_time FROM inserted ot)
	SELECT @finishTime = (SELECT ot.finish_time FROM inserted ot)

	IF @startTime >= @finishTime
	BEGIN
		ROLLBACK TRANSACTION
		PRINT 'Error! Start time later than finish time!'
	END
	ELSE
		PRINT 'Successful operation!'
END
GO

CREATE TRIGGER trg_using_car_insert_update
	ON using_car FOR INSERT, UPDATE
	AS
BEGIN
	DECLARE @startTime DATETIME
	DECLARE @finishTime DATETIME

	SELECT @startTime = (SELECT us.start_time FROM inserted us)
	SELECT @finishTime = (SELECT us.finish_time FROM inserted us)

	IF @startTime >= @finishTime
	BEGIN
		ROLLBACK TRANSACTION
		PRINT 'Error! Start time later than finish time!'
	END
	ELSE
		PRINT 'Successful operation!'
END
GO

CREATE TRIGGER trg_company_car_insert
	ON company_car AFTER INSERT
	AS
BEGIN
	DECLARE @company_cars_count INTEGER
	DECLARE @id_company INTEGER

	SELECT @id_company = (SELECT id_company FROM inserted)
	SELECT @company_cars_count = (SELECT ISNULL(c.cars_count, 0)
								  FROM inserted cc
									  JOIN company c
									    ON c.id = @id_company) + 1

	UPDATE company
	SET cars_count = @company_cars_count
	WHERE id = @id_company
END
GO

CREATE TRIGGER trg_company_car_update
	ON company_car AFTER UPDATE
	AS
BEGIN
	DECLARE @id_company_old INTEGER
	DECLARE @old_company_cars_count INTEGER
	DECLARE @id_company_new INTEGER
	DECLARE @new_company_cars_count INTEGER

	SELECT @id_company_old = (SELECT id_company FROM deleted)
	SELECT @id_company_new = (SELECT id_company FROM inserted)
	SELECT @old_company_cars_count = (SELECT c.cars_count
									  FROM deleted cc
										  JOIN company c
										    ON c.id = @id_company_old) - 1
	SELECT @new_company_cars_count = (SELECT ISNULL(c.cars_count, 0)
									  FROM inserted cc
										  JOIN company c
										    ON c.id = @id_company_new) + 1

	UPDATE company
	SET cars_count = @old_company_cars_count
	WHERE id = @id_company_old

	UPDATE company
	SET cars_count = @new_company_cars_count
	WHERE id = @id_company_new
END
GO

CREATE TRIGGER trg_company_car_delete
	ON company_car AFTER DELETE
	AS
BEGIN
	DECLARE @id_company INTEGER
	DECLARE @company_cars_count INTEGER

	SELECT @id_company = (SELECT id_company FROM deleted)
	SELECT @company_cars_count = (SELECT c.cars_count
									  FROM deleted cc
										  JOIN company c
										    ON c.id = @id_company) - 1
	UPDATE company
	SET cars_count = @company_cars_count
	WHERE id = @id_company
END
GO

CREATE TRIGGER trg_order_product_insert_update
	ON order_product INSTEAD OF INSERT, UPDATE
	AS
BEGIN
	DECLARE @id_order INTEGER
	DECLARE @id_product INTEGER
	DECLARE @id_type_car INTEGER
	DECLARE @id_type_product INTEGER

	SELECT @id_order = (SELECT id_order FROM inserted)
	SELECT @id_product = (SELECT id_product FROM inserted)

	SELECT @id_type_car = (SELECT c.id_type_car
						   FROM order_table ot
							   JOIN using_car uc
							     ON uc.id = ot.id_using_car
							   JOIN company_car cc
							     ON cc.id = uc.id_company_car
							   JOIN car c
							     ON c.id = cc.id_car
						   WHERE ot.id = @id_order)

	SELECT @id_type_product = (SELECT p.id_type_product 
							   FROM product p
							   WHERE p.id = @id_product)

	IF (SELECT COUNT(*)
		FROM type_car_type_product
		WHERE id_type_car = @id_type_car
				AND id_type_product = @id_type_product) = 0
	BEGIN
		ROLLBACK TRANSACTION
		PRINT 'Error! Type of car and type of product incompatible!'
	END
	ELSE
		BEGIN
			INSERT INTO order_product
				SELECT id_order, id_product
				FROM inserted

			PRINT 'Successful operation!'
		END
END
GO

-- examples
INSERT person(surname, name, patronymic, birthday, birthplace)
VALUES('Ivanov', 'Ivan', 'Ivanovich', '11.03.2018', 1)
GO
INSERT order_table(id_client, id_using_car, start_time, finish_time, start_location, finish_location, price)
VALUES(1, 1, '03.02.2017', '02.02.2017', 1, 2, 350)
GO

SELECT * FROM company WHERE id = 1
INSERT car(vin, id_model, id_color, id_type_car)
VALUES('4USBT53544LT26842', 1, 1, 1)
INSERT company_car(id_car, id_company)
VALUES(2, 1)
SELECT * FROM company WHERE id = 1
GO

INSERT type_product(type_code)
VALUES('heavy');
INSERT product(name, id_color, product_weight, id_type_product)
VALUES('Briks', 5, 300, 2);

INSERT order_product(id_order, id_product)
VALUES(1, 2)