#include <QtCore/QCoreApplication>
#include <QTimer>
#include "QVariant"
#include "QDebug"
#include <QGeoPolygon>

using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication app(argc, argv);

    QGeoPolygon poly;
    QGeoCoordinate vertex;
    QVariantList holePath0,holePath1;
    QVariant variantVertex;
    int i;

    double boundary0[][2]={{10,10},{10,-10},{-10,-10},{-10,10},{10,10}};
    double boundary1[][2]={{5,5},{-5,5},{-5,-5},{5,-5},{5,5}};
    double boundary2[][2]={{6,6},{-6,-6},{-6,4},{6,4},{6,6}};
    double boundary3[][2]={{5,-5},{-5,-5},{-5,-7},{5,-7},{5,-5}};


    for(i=0; i<(sizeof(boundary0)/sizeof(*boundary0));i++)
    {
        vertex.setLatitude(boundary0[i][0]); vertex.setLongitude(boundary0[i][1]);
        poly.addCoordinate(vertex);
    }

    for(i=0; i<(sizeof(boundary1)/sizeof(*boundary1));i++)
    {
        vertex.setLatitude(boundary1[i][0]); vertex.setLongitude(boundary1[i][1]);
        variantVertex.setValue(vertex);
        holePath0.append(variantVertex);
    }

    for(i=0; i<(sizeof(boundary2)/sizeof(*boundary2));i++)
    {
        vertex.setLatitude(boundary2[i][0]); vertex.setLongitude(boundary2[i][1]);
        variantVertex.setValue(vertex);
        holePath1.append(variantVertex);
    }

    poly.addHole(holePath0);
    poly.addHole(holePath1);

    vertex.setLatitude(0); vertex.setLongitude(0);


    vertex.setLatitude(0); vertex.setLongitude(6);  //contains: true, ambiguous; simple hole perimeter
    qDebug() << poly.contains(vertex);
    vertex.setLatitude(0); vertex.setLongitude(4);  //contains: false, unless overlapping holes becomes polygon; intersected hole perimeter
    qDebug() << poly.contains(vertex);
    vertex.setLatitude(-5); vertex.setLongitude(4); //contains: true, ambiguous; virtual vertex of the combined hole
    qDebug() << poly.contains(vertex);
    vertex.setLatitude(0); vertex.setLongitude(-5); //contains: false, crytical; common perimneter line between two holes
    qDebug() << poly.contains(vertex);

    qDebug() << poly.path();

    qDebug() << poly.holesCount();

    return 0;
}

