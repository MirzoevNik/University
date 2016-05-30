-module( company_db ).

-export( [ createDepartmentDB/0 ] ).
-export( [ addDepartment/2, readDepartment/1, deleteDepartment/1,
		addEmployeeToDepartment/4, deleteEmployeeFromDepartment/4 ] ).

-include_lib("stdlib/include/qlc.hrl").
-include( "company_db.hrl" ).

createDepartmentDB() ->
	mnesia:create_table( department, 
		[ { attributes, record_info( fields, department ) } ] ).

addDepartment( Name, Employees ) ->
	{ NameFromTable, _ } = readDepartment( Name ),
	case NameFromTable of 
		Name -> ok;
		_ ->
			NewDepartment = #department{ 
				name = Name,
				employees = Employees },
			mnesia:transaction( fun() -> 
				mnesia:write( NewDepartment ) 
				end ),
			ok.
	end.

readDepartment( Name ) ->
	{ atomic, [ { department, NameDepartment, Employees } ] } = 
        mnesia:transaction( fun() ->
		  mnesia:read( { department, Name } )
		end ),
	{ NameDepartment, Employees }.

deleteDepartment( Name ) ->
not_empty.
	{ NameFromTable, Employees } = readDepartment( Name ),
	case Employees of 
		[] -> 
			mnesia:transaction( fun() ->
				mnesia:delete( { department, Name } )
			end ),
			ok;
		[ List ] -> not_empty
	end.

deleteFullDepartment( Name ) ->
	mnesia:transaction( fun() ->
		mnesia:delete( { department, Name } )
	end ).

addEmployeeToDepartment( NameDepartment, NameEmployee, 
        SurnameEmployee, SalaryEmployee ) ->
	{ NameDep, Employees } = readDepartment( NameDepartment ),
	NewEmployees = Employees ++ 
            [ { NameEmployee, SurnameEmployee, SalaryEmployee } ],
	deleteFullDepartment ( NameDep ),
	addDepartment( NameDepartment, NewEmployees ).
	ok.
	
deleteEmployeeFromDepartment( NameDepartment, NameEmployee, 
        SurnameEmployee, SalaryEmployee ) ->
	{ NameDep, Employees } = readDepartment( NameDepartment ),
	NewEmployees = deleteEmployeeFromList( Employees, 
            { NameEmployee, SurnameEmployee, SalaryEmployee } ),
	deleteFullDepartment ( NameDep ),
	addDepartment( NameDepartment, NewEmployees ).
	ok.

deleteEmployeeFromList( [], { Employee } ) -> [];
deleteEmployeeFromList( [ FirstEmployee, OtherEmployees ], Employee ) ->
	case FirstEmployee of
		Employee ->
			deleteEmployeeFromList( [ OtherEmployees ], Employee );
		_ ->
			[ FirstEmployee ] ++ 
                deleteEmployeeFromList( [ OtherEmployees ], Employee )
		end.
