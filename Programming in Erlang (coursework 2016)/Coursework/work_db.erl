-module( work_db ).

-import( company_db, [ createDepartmentDB/0, 
	addDepartment/2, readDepartment/1, deleteDepartment/1,
	addEmployeeToDepartment/4, deleteEmployeeFromDepartment/4 ] ).
-import( lists, [foreach/2] ).

-export( [ init/0, start/0, 
	newDepartment/1, printDepartment/1, delDepartment/1,
	addNewEmployeeToDepartment/4, deleteOldEmployeeFromDepartment/4 ] ).

-include( "company_db.hrl" ).

init() ->
	mnesia:create_schema( [ node() ] ),
	mnesia:start(),
	createDepartmentDB(),
	mnesia:stop().

start() ->
	mnesia:start().

newDepartment( Name ) ->
	addDepartment( Name, [] ).

printDepartment( Name ) ->
	readDepartment( Name ).

delDepartment( Name ) ->
	deleteDepartment( Name ).

addNewEmployeeToDepartment( NameDepartment, NameEmployee, 
            SurnameEmployee, SalaryEmployee ) ->
	addEmployeeToDepartment( NameDepartment, NameEmployee, 
                SurnameEmployee, SalaryEmployee ).

deleteOldEmployeeFromDepartment( NameDepartment, NameEmployee, 
            SurnameEmployee, SalaryEmployee ) ->
	deleteEmployeeFromDepartment( NameDepartment, NameEmployee, 
                SurnameEmployee, SalaryEmployee ).