/*
 * Please see Appendix A of "Protocol Misidentification Made Easy with Format-Transforming Encryption"
 * url: http://dl.acm.org/citation.cfm?id=2516657
 *
 * and
 *
 * "Compression and ranking"
 * url: http://dl.acm.org/citation.cfm?id=22194
 *
 * for details about (un)ranking for regular languages.
 */


#ifndef _LIBFTE_SRC_RANKER_H
#define _LIBFTE_SRC_RANKER_H

#include <map>
#include <vector>

#include <stdint.h>
#include <gmpxx.h>

#include "exceptions.h"

namespace fte {

typedef std::vector<char> array_type_char_t1;
typedef std::vector<bool> array_type_bool_t1;
typedef std::vector<uint32_t> array_type_uint32_t1;
typedef std::vector< std::vector<uint32_t> > array_type_uint32_t2;
typedef std::vector< std::vector<mpz_class> > array_type_mpz_t2;
typedef std::vector< std::string > array_type_string_t1;

class ranker {

private:
    // the maximum value for which buildTable is computed
    uint32_t _fixed_slice;

    // our ranker start state
    uint32_t _start_state;

    // the number of states in our ranker
    uint32_t _num_states;

    // the number of symbols in our ranker alphabet
    uint32_t _num_symbols;

    // the symbols of our ranker alphabet
    array_type_uint32_t1 _symbols;

    // our mapping between integers and the symbols in our alphabet; ints -> chars
    std::map<uint32_t, char> _sigma;

    // the reverse mapping of sigma, chars -> ints
    std::map<char, uint32_t> _sigma_reverse;

    // the states in our ranker
    array_type_uint32_t1 _states;

    // our transitions table
    array_type_uint32_t2 _delta;

    // a lookup table used for additional performance gain
    // for each state we detect if all outgoing transitions are to the same state
    array_type_bool_t1 _delta_dense;

    // the set of final states in our ranker
    array_type_uint32_t1 _final_states;

    // buildTable builds a mapping from [q, i] -> n
    //   q: a state in our ranker
    //   i: an integer
    //   n: the number of words in our language that have a path to a final
    //      state that is exactly length i
    void _buildTable();

    // Checks the properties of our ranker, to ensure that we meet all constraints.
    // Throws an exception upon failure.
    void _validate();

    // _T is our cached table, the output of buildTable
    // For a state q and integer i, the value _T[q][i] is the number of unique
    // accepting paths of length exactly i from state q.
    array_type_mpz_t2 _T;

public:
    ranker() {};

    // The constructor of our rank/urank ranker class
    ranker( const std::string, const uint32_t );

    // our unrank function an int -> str mapping
    // given an integer i, return the ith lexicographically ordered string in
    // the language accepted by the ranker
    std::string unrank( const mpz_class );

    // our rank function performs the inverse operation of unrank
    mpz_class rank( const std::string );

    // given integers [n,m] returns the number of words accepted by the
    // ranker that are at least length n and no greater than length m
    mpz_class getNumWordsInLanguage( const uint32_t );
    mpz_class getNumWordsInLanguage( const uint32_t, const uint32_t );
};

} // namespace fte

#endif /* _LIBFTE_SRC_RANKER_H */