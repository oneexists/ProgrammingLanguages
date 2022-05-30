can_travel(Start, End) :- (road(Start, End,_)); (road(End, Start,_)); 
        (road(Start, Step,_), road(Step, End,_));
        (road(End, Step,_), road(Step, Start,_));
	(road(Step, Start,_), road(Step, End,_)).

distance(City1, City2, Distance) :- (road(City1, City2, Dist), Distance is Dist);
        (road(City2, City1, Dist), Distance is Dist);
	((road(City1, Step, Dist1), road(Step, City2, Dist2)), Distance is Dist1+Dist2);
	((road(City2, Step, Dist1), road(Step, City1, Dist2)), Distance is Dist1+Dist2);
	((road(Step, City1, Dist1), road(Step, City2, Dist2)), Distance is Dist1+Dist2).

max_list([Head|Tail], Max) :- (max_list(Tail, Value), Head > Value, Max is Head); 
	(max_list(Tail, Value), Head =< Value, Max is Value).
max_list([], 0).

road(st_paul, bloomington, 22).
road(bloomington, plymouth, 83).
road(st_paul, woodbury, 39).
road(bloomington, minneapolis, 43).
road(minneapolis, blaine, 67).
road(minneapolis, maplewood,   57).
road(minneapolis, plymouth,    39).
road(woodbury, maplewood,   18).
road(woodbury, stillwater,   26).
road(maplewood, hugo,  39).
road(stillwater, hugo,  16).
