/*
 * Marcos Cardinot <mcardinot@gmail.com>
 */

#ifndef CLUSTERING_LOOP_FUNCTIONS_H
#define CLUSTERING_LOOP_FUNCTIONS_H

#include <argos3/core/simulator/loop_functions.h>
#include <argos3/core/utility/math/rng.h>

#include <argos3/plugins/robots/kilobot/simulator/kilobot_entity.h>
#include <controllers/kilobot_clustering/kilobot_clustering.h>

#include "simplega.h"

#include <QFileInfo>

/**
 * @brief The CClusteringLoopFunctions class
 * @author Marcos Cardinot <mcardinot@gmail.com>
 */
class CClusteringLoopFunctions : public CLoopFunctions {

public:
   CClusteringLoopFunctions();
   virtual ~CClusteringLoopFunctions() {}

   virtual void Init(TConfigurationNode& t_node);
   virtual void Reset();
   virtual void PostExperiment();

   inline const int& getPopSize() const { return m_iPopSize; }
   inline const int& getMaxGenerations() const { return m_iMaxGenerations; }
   inline const int& getTournamentSize() const { return m_iTournamentSize; }
   inline const float& getMutationRate() const { return m_fMutationRate; }
   inline const float& getCrossoverRate() const { return m_fCrossoverRate; }
   inline const int& getLUTSize() const { return m_controllers.at(0)->getLUTSize(); }
   inline const CRange<Real>& getSpeedRange() const { return m_controllers.at(0)->getSpeedRange(); }

private:
   std::vector<CKilobotEntity*> m_entities;
   std::vector<CKilobotClustering*> m_controllers;
   CSimpleGA* m_cGA;
   CRandom::CRNG* m_pcRNG;

   int m_iPopSize;
   int m_iCurGeneration;
   bool m_bReadFromFile;
   CRange<Real> m_arenaSideX;
   CRange<Real> m_arenaSideY;

   int m_iMaxGenerations;
   int m_iTournamentSize;
   float m_fMutationRate;
   float m_fCrossoverRate;

   bool loadLUTMotor(int kbId, QString absoluteFilePath);
   bool robotExists(const uint32_t id);
};

#endif
