#include <iostream>

#include "agent.h"
#include "centroid.h"
#include "document.h"
#include "documentcollection.h"
#include "filter.h"

#include "filters/masseffect.h"
#include "filters/callofduty.h"
#include "filters/fifa.h"
#include "filters/worldofwarcraft.h"
#include "filters/praise.h"
#include "filters/shame.h"

using namespace std;

int main()
{
    std::cout << std::endl;
    std::cout << "K-MEANS CLUSTERING AGENT" << std::endl;

    Agent unguidedAgent, guidedAgent, guidedAgent2;
    DocumentCollection collection;
    collection.addDocument(new Document("../res/masseffect1.txt"));
    collection.addDocument(new Document("../res/masseffect2.txt"));
    collection.addDocument(new Document("../res/masseffect3.txt"));
    collection.addDocument(new Document("../res/masseffect4.txt"));
    collection.addDocument(new Document("../res/masseffect5.txt"));
    collection.addDocument(new Document("../res/masseffect6.txt"));
    collection.addDocument(new Document("../res/masseffect7.txt"));
    collection.addDocument(new Document("../res/fifa1.txt"));
    collection.addDocument(new Document("../res/fifa2.txt"));
    collection.addDocument(new Document("../res/fifa3.txt"));
    collection.addDocument(new Document("../res/fifa4.txt"));
    collection.addDocument(new Document("../res/fifa5.txt"));
    collection.addDocument(new Document("../res/fifa6.txt"));
    collection.addDocument(new Document("../res/fifa7.txt"));
    collection.addDocument(new Document("../res/wow1.txt"));
    collection.addDocument(new Document("../res/wow2.txt"));
    collection.addDocument(new Document("../res/wow3.txt"));
    collection.addDocument(new Document("../res/wow4.txt"));
    collection.addDocument(new Document("../res/wow5.txt"));
    collection.addDocument(new Document("../res/wow6.txt"));
    collection.addDocument(new Document("../res/wow7.txt"));
    collection.addDocument(new Document("../res/cod1.txt"));
    collection.addDocument(new Document("../res/cod2.txt"));
    collection.addDocument(new Document("../res/cod3.txt"));
    collection.addDocument(new Document("../res/cod4.txt"));
    collection.addDocument(new Document("../res/cod5.txt"));
    collection.addDocument(new Document("../res/cod6.txt"));
    collection.addDocument(new Document("../res/cod7.txt"));

    std::vector<Filter*> gameFilters;
    gameFilters.push_back(new MassEffect());
    gameFilters.push_back(new Fifa());
    gameFilters.push_back(new WorldOfWarcraft());
    gameFilters.push_back(new CallOfDuty());

    std::vector<Filter*> serviceFilters;
    serviceFilters.push_back(new Shame());
    serviceFilters.push_back(new Praise());

    ///Unguided clustering, note: VERY SLOW
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "----------Unguided clustering----------" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::vector<Data*> dataSetWithoutFilters;
    dataSetWithoutFilters = unguidedAgent.processDocuments(collection);

    std::vector<Centroid*> resultSetWithoutSeed;
    int counter1 = 0;
    resultSetWithoutSeed = unguidedAgent.prepareDocumentCluster(4, dataSetWithoutFilters, counter1);

    for(int i = 0; i < resultSetWithoutSeed.size(); i++)
    {
        std::cout << "Cluster #" << i << std::endl;
        resultSetWithoutSeed[i]->printGroup();
    }

    std::cout << "Number of iterations required to find result: " << counter1 << std::endl;

    ///Clustering with a filter and seed
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "-----------Seeded clustering-----------" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::vector<Data*> dataSetWithFilters;
    dataSetWithFilters = guidedAgent.processDocuments(collection, gameFilters);

    std::vector<Data*> seeds;
    seeds.push_back(dataSetWithFilters[2]);
    seeds.push_back(dataSetWithFilters[7]);
    seeds.push_back(dataSetWithFilters[14]);
    seeds.push_back(dataSetWithFilters[21]);

    std::vector<Centroid*> resultSetWithSeed;
    int counter2 = 0;
    resultSetWithSeed = guidedAgent.prepareDocumentCluster(dataSetWithFilters, seeds, counter2);

    for(int i = 0; i < resultSetWithSeed.size(); i++)
    {
        std::cout << "Filter: " << gameFilters[i]->getName() << std::endl;
        resultSetWithSeed[i]->printGroup();
    }

    std::cout << "Number of iterations required to find result: " << counter2 << std::endl;

    ///Clustering with a filter but without a seed.
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "----------Filtered clustering----------" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::vector<Data*> dataSetWithFilters2;
    dataSetWithFilters2 = guidedAgent2.processDocuments(collection, gameFilters);

    std::vector<Centroid*> resultSetWithoutSeedWithFilter;
    int counter3 = 0;
    resultSetWithoutSeedWithFilter = guidedAgent2.prepareDocumentCluster(2, dataSetWithFilters2, counter3);

    for(int i = 0; i < resultSetWithoutSeedWithFilter.size(); i++)
    {
        std::cout << "Filter: " << serviceFilters[i]->getName() << std::endl;
        resultSetWithoutSeedWithFilter[i]->printGroup();
    }

    std::cout << "Number of iterations required to find result: " << counter3 << std::endl;


    return 0;
}

