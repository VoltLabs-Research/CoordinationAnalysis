#pragma once

#include <opendxa/core/opendxa.h>
#include <opendxa/core/lammps_parser.h>
#include <nlohmann/json.hpp>
#include <opendxa/core/particle_property.h>
#include <opendxa/analysis/coordination_analysis.h>
#include <string>

namespace OpenDXA{
using json = nlohmann::json;

class CoordinationWrapper{
public:
    CoordinationWrapper();

    void setCutoff(double cutoff);
    void setRdfBins(int bins);

    json compute(
        const LammpsParser::Frame &frame,
        const std::string &outputFilename = ""
    );

private:
    double _cutoff;
    int _rdfBins;


    std::shared_ptr<Particles::ParticleProperty> createPositionProperty(const LammpsParser::Frame &frame);
    bool validateSimulationCell(const SimulationCell &cell);
};

}