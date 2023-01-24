#include "Control.h"

void Control::GenerateLatexReport(string projectRoute, Model *modelsUsed, string projectName)
{
    vector<string> initialValuesString = { "S_0", "I_0", "R_0", "t_0", "t_f", "dt" };

    vector<double> constants;
    vector<double> initialValues;

    // double N = initialValues[0] + initialValues[1] + initialValues[2];

    double*Max = Maximum("data/" + projectName + "/result-" + modelsUsed->modelName + ".dat", Infected);

    string pathConstants = projectRoute + "/const-" + modelsUsed->modelName + ".dat";
    string pathInitialValues = projectRoute + "/init-" + modelsUsed->modelName + ".dat";

    string pathGraphImg = projectRoute + "/graph-" + modelsUsed->modelName + ".png";
    string pathPhaseImg = projectRoute + "/phase-" + modelsUsed->modelName + ".png";

    constants = LoadData(pathConstants);
    initialValues = LoadData(pathInitialValues);

    string pathReport = projectRoute + "/report-" + modelsUsed->modelName + ".tex";
    ofstream report(pathReport);

    report << "\\documentclass{article}" << endl;
    report << "\\usepackage[utf8]{inputenc}" << endl;
    report << "\\usepackage[spanish]{babel}" << endl;
    report << "\\usepackage{amsmath}" << endl;
    report << "\\usepackage{multicol}" << endl;
    report << "\\usepackage{graphicx}" << endl;
    report << "\\usepackage{float}" << endl;
    report << "\\usepackage{geometry}" << endl;
    report << "\\usepackage{listings}" << endl;
    report << "\\usepackage{enumitem}" << endl;
    report << "" << endl;


    report << "\\title{Report of the model " << modelsUsed->modelName << "}" << endl;
    report << "\\author{PropEnfermedades APP}" << endl;
    report << "\\date{}" << endl;
    report << "\\geometry{letterpaper, top=2.54cm, bottom=2.54cm, left=3cm, right=3cm}    " << endl;
    report << "\\setlength{\\parindent}{0cm}" << endl;
    report << "\\setlength{\\parskip}{0.2em}" << endl;
    report << "" << endl;


    report << "\\begin{document}" << endl;
    report << "\\maketitle" << endl;

    report << "\\section{Model}" << endl;
    report << "Next we show the model used in the simulation." << endl;
    
    report << "\\subsection*{Description}" << endl;
    report << modelsUsed->modelDescription << endl;
    
    report << "\\subsection*{Equations}" << endl;
    report << "\\begin{equation}" << endl;
    report << "\\begin{split}" << endl;
    report << modelsUsed->modelEquations << endl;
    report << "\\end{split}" << endl;    
    report << "\\end{equation}" << endl;    
    
    report << "\\subsection*{Parameters}" << endl;
    report << "\\begin{itemize}" << endl;
    for (int i = 0; i < (int)modelsUsed->modelParameters.size(); i++)
    {
        report << "\\item $" << modelsUsed->modelParameters[i] << " = " << constants[i] << "$. " << endl;
    }
    report << "\\end{itemize}" << endl;

    report << "\\subsection*{Initial values}" << endl;
    report << "\\begin{itemize}" << endl;
    for (int i = 0; i < (int)initialValues.size(); i++)
    {
        report << "\\item $" << initialValuesString[i] << " = " << initialValues[i] << "$. " << endl;
    }
    report << "\\end{itemize}" << endl;

    report << "\\section*{Results}" << endl;
    report << "The maximum infected population is " << Max[0] << " is reached on day " << Max[1] << "." << endl;
    report << "Next we show the results of the simulation using the model " << modelsUsed->modelName << " with the parameters and initial values shown above." << endl;
    report << "\\begin{figure}[H]" << endl;
    report << "\\centering" << endl;
    report << "\\includegraphics[width=0.8\\textwidth]{" << pathGraphImg << "}" << endl;
    report << "\\caption{Graph of the model " << modelsUsed->modelName << "}" << endl;
    report << "\\end{figure}" << endl;

    report << "\\begin{figure}[H]" << endl;
    report << "\\centering" << endl;
    report << "\\includegraphics[width=0.8\\textwidth]{" << pathPhaseImg << "}" << endl;
    report << "\\caption{Phase portrait of the model " << modelsUsed->modelName << "}" << endl;
    report << "\\end{figure}" << endl;

    report << "\\end{document}" << endl;

    report.close();


    string latexFolder = projectRoute + "/reports";
    mkdir(latexFolder.c_str(), 0777);
    string command = "pdflatex -output-directory=" + latexFolder + " " + pathReport;
    system(command.c_str());
}