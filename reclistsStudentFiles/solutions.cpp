#include "reclists.hpp"
#include "solutions.hpp"

list append(list p, list q) {

    if( is_null(p) ) {
        return q;
    }
    return cons( car(p), append( cdr(p), q ) );
}

int numNodesAtTheTopLevel(list p) {
    // p is one of
    //    a null list
    //    an atom
    //    a recursive list

    // The function returns the number of nodes at the top-level
    // of p.

    if( is_null(p) )
        return 0;
    if( is_atom(p) )
        return 1;
    return 1 + numNodesAtTheTopLevel(cdr(p));
}
// works
bool is_lat(list p) { // done

    if(is_null(p)){
        return true;
    }
    if(!is_atom(car(p))){
        return false;
    }
    return is_lat(cdr(p));
}
// works
bool member (list p, list q) {
    if (is_null(q)) {
        return false;
    }

    if (is_atom(car(q))) {

        if (eq(p, car(q))) {
            return true;
        }
        else {
            return member(p, cdr(q));
        }
    }
    return member(p, car(q)) || member(p,cdr(q));
}
// works
list last(list p) {

    if(is_null(p)){
        return null();
    }
    if(is_null(cdr(p))){

        if(is_atom(car(p))){
            return car(p);
        } else {
            return last(car(p));
        }
    }

    return last(cdr(p));
}
// works
list list_pair(list p, list q) {

    if (is_null(p)){
        return null();
    }

    return cons(cons(car(p),cons(car(q),null())), list_pair(cdr(p),cdr(q)));
}
// works
list firsts (list p) {

    if( is_null(p) ) {
        return p;
    }

    return cons(car(car(p)),firsts(cdr(p)));
}

// works
list flat(list p) {

    if(is_null(p))
        return null();

    if(is_atom(car(p)))
        return cons(car(p),flat(cdr(p)));

    if(!is_atom(car(p))){
        return append(flat(car(p)),flat(cdr(p)));
    }
}
// works
bool two_the_same (list p, list q) {

    if(is_null(p)){
        return false;
    }

    if(is_atom(car(p))){
        if(member(car(p),q)){
            return true;
        } else {
            return false;
        }

    }
    if(!is_atom(p)) {
        return two_the_same(car(p), q) || two_the_same(cdr(p), q);
    }

    return two_the_same(cdr(p),q);
}
// works
bool equal(list p, list q) {

    if(is_null(p) && is_null(q)){
        return true;
    }

    if(is_null(p) || is_null(q)){
        return false;
    }

    if(is_atom(car(p)) && is_atom(car(q))){
        if(!eq(car(p),car(q))){
            return false;
        }

        return equal(cdr(p),cdr(q));
    }


    if(!is_atom(car(p)) && !is_atom(cdr(p))){
        return equal(car(p),car(q)) && equal(cdr(p),cdr(q));
    }

    return false;
}
// partially done
list total_reverse(list p) {

    if( is_null(p) ) {
        return null();
    }

    cons(total_reverse(cdr(p)),car(p));
}
// works
list shape(list p) {

    if(is_null(p)){
        return p;
    }
    if(is_atom(car(p)) && !is_atom(cdr(p))){
        return append(null(),shape(cdr(p)));
    }
    else {
        return cons(shape(car(p)),shape(cdr(p)));
    }

}
// works
list intersection(list p, list q) {
    if (is_null(p)) {
        return p;
    }
    if(member(car(p),q)){
        return cons(car(p),intersection(cdr(p),q));
    }
    return intersection(cdr(p),q);
}
// works partially
list list_union(list p, list q) {
    if (is_null(p)) {
        return q;
    } else if (is_null(q)){
        return p;
    }

    if(!member(car(p),q)){
        return cons(car(p),cons(car(q),list_union(cdr(p),cdr(q))));
    } else{
        if(!is_null(cdr(p)) && is_atom(car(cdr(p))))
            if(eq(car(p),car(cdr(p)))){
                return /*cons(car(q), */list_union(cdr(p),cdr(q)/*)*/);

            } else {
        return cons(car(cdr(q)), list_union(cdr(p),cdr(q)));
        }
    }

}