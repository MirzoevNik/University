USE mirzoevnik
GO

-- 1
SELECT c.vin, cmo.model_code, cma.mark_code 
FROM car c
	JOIN car_model cmo
	  ON cmo.id = c.id_model
	JOIN car_mark cma
	  ON cma.id = cmo.id_mark
GO
SELECT c.vin, cmo.model_code, cma.mark_code 
FROM car c
	JOIN car_model cmo
	  ON cmo.id = c.id_model
	RIGHT OUTER JOIN car_mark cma
	  ON cma.id = cmo.id_mark
GO
SELECT co.color_code, cma.mark_code 
FROM car_mark cma
	CROSS JOIN color co
GO
SELECT co.color_code, cma.mark_code 
FROM car_mark cma
	CROSS APPLY
	(SELECT * 
	 FROM color 
	 WHERE id = 2) co
GO
SELECT ls.house_number AS start_house_number,
	   lf.house_number AS finish_house_number
FROM order_table ot
	JOIN location ls
	  ON ot.start_location = ls.id
	JOIN location lf
	  ON ot.finish_location = lf.id
GO

-- 2
SELECT *
FROM driver d
WHERE EXISTS (SELECT * FROM person p);

SELECT *
FROM driver d
WHERE d.id_person IN (0, 2);

SELECT *
FROM driver d
WHERE d.id_person BETWEEN 0 AND 2;

SELECT *
FROM color c
WHERE c.color_code LIKE 'White'

SELECT * 
FROM car_model cm
WHERE cm.id_mark >= ALL(SELECT MAX(cm.id_mark) FROM car_model cm);

SELECT * 
FROM car_model cm
WHERE cm.id_mark >= ANY(SELECT MAX(cm.id_mark) id_mark
						FROM car_model cm
						GROUP BY cm.id
						HAVING MAX(cm.id_mark) > 0);

-- 3
SELECT CASE WHEN cl.id = cl.id_person
            THEN p.surname + ' ' + p.name + ' ' + p.patronymic
            WHEN cl.id = cl.id_company
            THEN co.name
	     END full_name
FROM client cl
	LEFT JOIN person p
	  ON p.id = cl.id_person
	LEFT JOIN company co
	  ON co.id = cl.id_company

-- 4
SELECT p.id, p.product_weight, CAST(p.product_weight AS int) product_weight_int
FROM product p;

SELECT (CONVERT(varchar, d.experience) + ' years') exper
FROM driver d;

SELECT c.id, 
	   ISNULL(STR(c.id_person), 'Not NaturalPerson') id_person,
	   NULLIF(c.id_person, c.id_company) any_id
FROM client c;

SELECT CHOOSE(dcl.id_category_license, 'A', 'B', 'C', 'D') category
FROM driver_category_license dcl;

SELECT IIF(c.id_person IS NOT NULL, STR(c.id_person), 'Not NaturalPerson') id_person
FROM client c;

-- 5
SELECT REPLACE(c.city_code, 'a', 'A') city_code_replace
FROM city c;

SELECT SUBSTRING(c.city_code, 1, 3) city_code_substring
FROM city c;

SELECT STUFF(c.city_code, 1, 2, c.city_code) city_code_staff
FROM city c;

SELECT cl.category_code, UNICODE(cl.category_code) category_code_value
FROM category_license cl

SELECT LOWER(c.city_code) city_code
FROM city c;

SELECT UPPER(c.city_code) city_code
FROM city c;

-- 6
SELECT p.id, DATEPART(year, p.birthday) birthday_year
FROM person p;

SELECT p.id, p.birthday, DATEADD(day, 2, p.birthday) birthday_add
FROM person p;

SELECT uc.start_time, uc.finish_time, DATEDIFF(day, uc.start_time, uc.finish_time) diff
FROM using_car uc;

SELECT GETDATE(), SYSDATETIMEOFFSET();

-- 7
SELECT cm.id_mark
FROM car_model cm
GROUP BY cm.id_mark;

SELECT cm.id, MAX(cm.id_mark) id_mark
FROM car_model cm
GROUP BY cm.id
HAVING MAX(cm.id_mark) > 1
ORDER BY cm.id DESC;