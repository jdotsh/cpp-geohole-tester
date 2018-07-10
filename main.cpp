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
    QVariantList holePath;
    QVariant variantVertex;
    int i;

    double boundary0[][2]={{10,10},{10,-10},{-10,-10},{-10,10},{10,10}};
    double boundary1[][2]={{5,5},{5,-5},{-5,-5},{-5,5},{5,5}};

    for(i=0; i<(sizeof(boundary0)/sizeof(*boundary0));i++)
    {
     vertex.setLatitude(boundary0[i][0]); vertex.setLongitude(boundary0[i][1]);
     poly.addCoordinate(vertex);
    }

    for(i=0; i<(sizeof(boundary1)/sizeof(*boundary1));i++)
    {
     vertex.setLatitude(boundary1[i][0]); vertex.setLongitude(boundary1[i][1]);
     variantVertex.setValue(vertex);
     holePath.append(variantVertex);
    }

    poly.addHole(holePath);

    vertex.setLatitude(0); vertex.setLongitude(0);

    qDebug() << poly.path();

    qDebug() << poly.holesCount();

    qDebug() << poly.contains(vertex);

    return 0;
}

