#6. Mini Expert System
!apt-get update -qq
!apt-get install -y swi-prolog-nox

%%writefile expert.pl

animal(dog) :-
    has_fur,
    barks.

animal(cat) :-
    has_fur,
    meows.

animal(bird) :-
    has_wings,
    lays_eggs.

has_fur.
barks.

% Ask the expert system
:- initialization(main).

main :-
    ( animal(X) ->
        format('Animal identified: ~w ~n', [X])
    ;
        writeln('Animal not identified')
    ),
    halt.



/*
        % Facts
        has_fur.
        barks.

        % Rules
        animal(dog) :-
        has_fur,
        barks.

        animal(cat) :-
        has_fur,
        meows.

        animal(bird) :-
        has_wings,
        lays_eggs.

% Ask the expert system
:- initialization(main).

    main :-
        ( animal(X) ->
            format('Animal identified: ~w~n', [X])
        ;
            writeln('Animal not identified')
        ),
        halt.
*/