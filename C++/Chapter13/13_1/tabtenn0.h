#ifndef TABLENNO_H_
#define TABLENNO_H_

#include <string>
using std::string;

class TableTennisPlayer{
    private:
        string firstName;
        string lastName;
        bool hasTable;

    public:
        TableTennisPlayer(const string & fn = "none", 
                          const string & ln = "none", bool ht = false);
        void Name() const;  // 函数不可修改类的成员
        bool HasTable() const {return hasTable;}
        void ResetTable(bool v) {hasTable = v;}
};

class RatedPlayer : public TableTennisPlayer
{
private:
    unsigned int rating;        // add a data number
public:
    RatedPlayer(unsigned int r = 0, const string & fn = "none", const string & ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() const { return rating; }
    void ResetRating (unsigned int r) { rating = r; }
};

#endif
