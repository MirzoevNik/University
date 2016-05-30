
-module( test_proc ).

-export([ main/0, start/1, newProccess/2 ]).


main() ->
	%Count_of_proccesses1 = 1,
	%io:format( "~nStart of new procces~n" ),
	%{ Time1, ok } = timer:tc( test_proc, start, [ Count_of_proccesses1 ] ),
	%io:format( "Count of proccesses: ~w~nTime: ~w~n", [ Count_of_proccesses1, Time1 ] ).

	%Count_of_proccesses2 = 2,
	%io:format( "~nStart of new procces~n" ),
	%{ Time2, ok } = timer:tc( test_proc, start, [ Count_of_proccesses2 ] ),
	%io:format( "Count of proccesses: ~w~nTime: ~w~n", [ Count_of_proccesses2, Time2 ] ).

	%Count_of_proccesses10 = 10,
	%io:format( "~nStart of new procces~n" ),
	%{ Time10, ok } = timer:tc( test_proc, start, [ Count_of_proccesses10 ] ),
	%io:format( "Count of proccesses: ~w~nTime: ~w~n", [ Count_of_proccesses10, Time10 ] ).

	%Count_of_proccesses50 = 50,
	%io:format( "~nStart of new procces~n" ),
	%{ Time50, ok } = timer:tc( test_proc, start, [ Count_of_proccesses50 ] ),
	%io:format( "Count of proccesses: ~w~nTime: ~w~n", [ Count_of_proccesses50, Time50 ] ).

	Count_of_proccesses100 = 100,
	io:format( "~nStart of new procces~n" ),
	{ Time100, ok } = timer:tc( test_proc, start, [ Count_of_proccesses100 ] ),
	io:format( "Count of proccesses: ~w~nTime: ~w~n", [ Count_of_proccesses100, Time100 ] ).

	%Count_of_proccesses1000 = 1000,
	%io:format( "~nStart of new procces~n" ),
	%{ Time1000, ok } = timer:tc( test_proc, start, [ Count_of_proccesses1000 ] ),
	%io:format( "Count of proccesses: ~w~nTime: ~w~n", [ Count_of_proccesses1000, Time1000 ] ).

	%Count_of_proccesses10000 = 10000,
	%io:format( "~nStart of new procces~n" ),
	%{ Time10000, ok } = timer:tc( test_proc, start, [ Count_of_proccesses10000 ] ),
	%io:format( "Count of proccesses: ~w~nTime: ~w~n", [ Count_of_proccesses10000, Time10000 ] ).


start( Number ) ->
    
	newProccess( Number, self() ).
    


newProccess( 1, Pid ) ->
 
	io:format( "New proccess was starting.~nNumber of proccess: ~w~n", [ 1 ] ),  
	Pid ! ok;

newProccess( Number, Pid ) ->
    
	NewPid = spawn( test_proc, newProccess, [ Number - 1, Pid ] ),
    
	io:format( "New proccess was starting.~nNumber of proccess: ~w~n", [ Number ] ),  
	NewPid ! ok,
    
	receive ok ->      
		ok
    
	end.