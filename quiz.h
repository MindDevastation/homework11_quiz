#ifndef QUIZ_H
#define QUIZ_H


#include <map>
#include <QString>
class quiz
{
public:
    quiz();
    std::map<int, QString> Qmap;
    std::map<int, QString> QmapNum;
    std::vector<int> box{ 1,2,3,4,5};
};

#endif // QUIZ_H
