/*************************************************************************/
/*                                                                       */
/*                            LD-CELP  G.728                             */
/*                                                                       */
/*    Low-Delay Code Excitation Linear Prediction speech compression.    */
/*                                                                       */
/*    Code edited by Michael Concannon.                                  */
/*    Based on code written by Alex Zatsman, Analog Devices 1993         */
/*                                                                       */
/*************************************************************************/

#include "data.h"
#include "common.h"

const real cb_shape[128][5]=
{
{  0.326171875, -1.440429688, -0.612304688, -0.874023438, -1.246582031},
{ -2.457031250, -2.234863281, -0.510253906,  1.419921875,  1.620117188},
{ -1.376464844, -1.307128906, -0.462890625, -1.379394531, -2.172851563},
{ -3.261230469, -0.166015625,  0.723632813, -0.623046875,  0.616210938},
{ -0.274414063, -3.299316406,  0.625488281,  0.087402344, -0.622070313},
{ -1.226562500, -3.481445313, -2.404785156,  3.375488281,  1.177246094},
{ -1.209960938, -0.076171875,  2.286621094, -1.891113281,  0.000000000},
{ -4.007812500,  1.044921875, -0.233398438, -1.359863281,  0.260253906},
{  0.922363281,  1.347167969,  0.674316406, -3.395996094, -2.887207031},
{  2.481445313, -1.201171875, -2.821289063,  0.877441406,  0.277343750},
{ -1.078125000, -1.615722656, -2.208496094, -3.044921875, -3.664550781},
{ -1.327636719,  2.127929688, -1.458984375, -0.561035156,  1.300781250},
{  0.614746094,  0.485839844,  1.323730469, -1.203125000, -5.073242188},
{  0.840820313, -3.695800781, -1.338867188,  1.060058594, -1.137207031},
{  0.503906250,  0.364746094, -0.418945313, -3.879882813, -6.270996094},
{  1.516601563,  2.371093750, -2.047363281, -1.240722656,  0.505371094},
{  0.909179688, -0.468750000, -3.236328125,  0.200195313,  2.872070313},
{ -1.217285156, -1.283203125, -1.953125000, -0.029296875,  3.516601563},
{ -1.304687500,  0.706054688,  0.750000000, -1.870605469,  0.602050781},
{ -2.588867188,  3.375000000,  0.775878906, -2.044433594,  1.789550781},
{ -1.687500000, -3.989257813, -3.764160156,  0.675781250,  2.293945313},
{ -2.294433594, -3.031738281, -5.457031250,  3.957031250,  8.217773438},
{  0.454101563,  3.419921875,  0.619628906, -4.383300781,  1.253417969},
{  2.270019531,  5.763671875,  1.680175781, -2.762207031,  0.585449219},
{  1.241210938, -0.089355469, -4.325683594, -3.894531250,  1.577148438},
{ -1.402343750, -0.981933594, -4.742675781, -4.094238281,  6.339355469},
{  1.506835938,  1.044921875, -1.796875000, -4.708496094, -1.414062500},
{ -3.715332031,  3.181152344, -1.114746094, -1.231445313,  3.091796875},
{ -1.627441406, -2.744140625, -4.458007813, -5.435058594,  2.706542969},
{ -0.198730469, -3.281738281, -8.528320313, -1.410644531,  5.648437500},
{  1.802734375,  3.318359375, -0.127929688, -5.295898438, -0.906250000},
{  3.552246094,  6.544921875, -1.459472656, -5.173339844,  2.410156250},
{  0.119140625, -1.083496094,  1.296875000,  1.843750000, -2.642578125},
{ -1.974121094, -2.897460938,  1.040527344,  0.421386719, -1.399414063},
{ -1.612304688,  0.851074219, -0.979492188, -0.062500000, -1.001953125},
{ -3.105957031,  1.631835938, -0.772949219, -0.010253906,  0.557617188},
{ -1.873535156, -0.894042969,  3.123535156,  1.242675781, -1.390625000},
{ -4.556640625, -3.187500000,  2.592285156,  0.969726563, -1.096191406},
{ -2.192382813,  0.365234375,  0.944824219, -1.478027344, -0.240722656},
{ -4.519042969,  2.620117188,  1.559082031, -2.193847656,  0.871093750},
{  2.335937500, -0.180664063,  0.911132813,  0.516113281, -0.922363281},
{  3.584960938, -1.313476563, -1.258300781,  0.330078125, -0.298339844},
{ -0.245117188,  1.091308594, -0.903320313, -0.867675781, -1.000488281},
{  0.493652344,  1.894531250, -1.203613281,  1.078613281, -0.074218750},
{  1.265625000,  1.381347656,  2.728515625,  1.386230469, -3.567382813},
{ -1.488769531, -2.401367188,  2.907714844,  4.492675781, -2.171386719},
{  0.340332031,  1.908203125,  2.831054688, -2.173339844, -2.267578125},
{ -1.035644531,  2.658203125, -1.254882813,  0.156738281, -0.586914063},
{  1.389648438, -1.018554688,  1.724609375,  0.276367188, -0.345703125},
{ -2.089355469,  0.463867188,  2.431640625,  1.830566406,  0.220703125},
{ -1.212890625,  1.709960938,  0.839355469, -0.083007813,  0.116210938},
{ -1.677246094,  0.128417969,  1.032226563, -0.979003906,  1.152832031},
{ -3.583007813, -0.589843750,  4.563964844, -0.593750000, -1.959472656},
{ -6.590820313, -0.214355469,  3.919921875, -2.066406250,  0.176269531},
{ -1.820800781,  2.652832031,  0.978515625, -2.308105469, -0.614746094},
{ -1.946289063,  3.780761719,  4.115722656, -1.802246094, -0.481933594},
{  2.538085938, -0.206542969,  0.561523438, -0.625488281,  0.398437500},
{  3.617675781,  2.006347656, -1.928222656,  1.313476563,  0.014648438},
{  0.608398438,  1.491699219, -0.017089844, -0.668945313, -0.120117188},
{ -0.727050781,  2.751464844, -0.331054688, -1.282714844,  1.547851563},
{  2.358398438, -2.238769531,  0.980468750, -0.518554688,  0.390136719},
{ -0.062988281,  0.350097656,  2.243164063,  7.293457031,  5.227539063},
{  0.203613281,  1.347167969,  0.903320313, -2.469238281, -0.562988281},
{ -1.897949219,  3.594238281, -2.816406250,  2.092285156,  0.325195313},
{  0.704589844, -0.458007813,  0.009765625, -1.034667969, -0.828613281},
{ -1.812500000, -1.661132813, -1.080078125,  0.053710938,  1.042968750},
{ -1.441406250,  0.005859375, -0.765625000, -1.708984375, -0.905761719},
{ -0.642089844, -0.845214844,  0.566406250, -0.272460938,  0.834472656},
{  0.042968750, -2.230957031,  0.094726563, -0.221679688, -1.443847656},
{ -1.386230469, -0.813476563, -0.133300781,  1.017578125, -0.075683594},
{ -0.092285156, -1.160156250,  0.812011719, -0.507812500, -1.195800781},
{ -1.387695313, -0.668457031,  0.310546875, -0.121093750, -1.307128906},
{  0.740722656,  0.038574219, -1.471191406, -1.791503906, -0.475097656},
{  0.934082031, -1.217285156, -2.593750000, -0.365722656,  0.620605469},
{ -1.417480469, -1.623046875, -1.833984375, -1.801757813, -0.893066406},
{ -1.422363281, -0.755371094, -1.347656250, -0.686523438,  0.548828125},
{  0.900390625, -0.895507813,  0.222656250,  0.344726563, -2.085937500},
{  0.228027344, -2.078125000, -0.932128906,  0.742675781,  0.553710938},
{ -0.062011719, -0.485351563, -0.311035156, -0.728027344, -3.170898438},
{  0.426269531, -0.998535156, -1.869140625, -1.363281250, -0.282226563},
{  1.128417969, -0.887207031,  1.285156250, -1.490234375,  0.960937500},
{  0.312988281,  0.583007813,  0.924316406,  2.005371094,  3.096679688},
{ -0.021972656,  0.584960938,  1.054687500, -0.707519531,  1.075683594},
{ -0.978515625,  0.836425781,  1.717773438,  1.294921875,  2.075683594},
{  1.433593750, -1.937500000,  0.625000000,  0.063964844, -0.720703125},
{  1.380371094,  0.003906250, -0.941406250,  1.297851563,  1.715332031},
{  1.562011719, -0.398437500,  1.312011719, -0.850097656, -0.687011719},
{  1.439453125,  1.967285156,  0.192382813, -0.123535156,  0.633789063},
{  2.092773438,  0.024902344, -2.200683594, -0.015625000, -0.321777344},
{  1.905761719,  2.756835938, -2.728515625, -1.265625000,  2.786621094},
{ -0.295898438,  0.602539063, -0.784667969, -2.532714844,  0.324218750},
{ -0.256347656,  1.767578125, -1.070312500, -1.233886719,  0.833496094},
{  2.098144531, -1.587402344, -1.114746094,  0.396484375, -1.105468750},
{  2.814941406,  0.257812500, -1.604980469,  0.660156250,  0.816406250},
{  1.335449219,  0.605957031, -0.538574219, -1.598144531, -1.663574219},
{  1.969238281,  0.804687500, -1.447753906, -0.573242188,  0.705078125},
{  0.036132813,  0.448242188,  0.976074219,  0.446777344, -0.500976563},
{ -1.218750000, -0.783691406,  0.993164063,  1.440429688,  0.111816406},
{ -1.058593750,  0.994628906,  0.007324219, -0.617187500, -0.101562500},
{ -1.734375000,  0.747070313,  0.283691406,  0.728027344,  0.469726563},
{ -1.275878906, -1.141601563,  1.768066406, -0.726562500, -1.066894531},
{ -0.853027344,  0.039550781,  2.704101563,  0.699218750, -1.102050781},
{ -0.497558594,  0.423339844,  0.104492188, -1.115234375, -0.737304688},
{ -0.822265625,  1.375000000, -0.111816406,  1.245605469, -0.678222656},
{  1.321777344,  0.246093750,  0.233886719,  1.358886719, -0.492675781},
{  1.229003906, -0.726074219, -0.779296875,  0.303222656,  0.941894531},
{ -0.072265625,  1.077148438, -2.093750000,  0.630859375, -0.684082031},
{ -0.257324219,  0.606933594, -1.333496094,  0.932128906,  0.625000000},
{  1.049316406, -0.732910156,  1.800781250,  0.297851563, -2.241699219},
{  1.614257813, -1.645019531,  0.915527344,  1.775390625, -0.594238281},
{  1.256835938,  1.227050781,  0.707519531, -1.500976563, -2.431152344},
{  0.397460938,  0.891601563, -1.219238281,  2.067382813, -1.990722656},
{  0.812500000, -0.107421875,  1.668945313,  0.489257813,  0.544433594},
{  0.381347656,  0.809570313,  1.913574219,  2.993164063,  1.533203125},
{  0.560546875,  1.984863281,  0.740234375,  0.397949219,  0.097167969},
{  0.581542969,  1.215332031,  1.250488281,  1.182128906,  1.192871094},
{  0.375976563, -2.888183594,  2.692871094, -0.179687500, -1.562011719},
{  0.581054688,  0.511230469,  1.827148438,  3.382324219, -1.020019531},
{  0.142578125,  1.513183594,  2.103515625, -0.370117188, -1.198730469},
{  0.255371094,  1.914550781,  1.974609375,  0.676757813,  0.041503906},
{  2.132324219,  0.491210938, -0.611328125, -0.715820313, -0.675292969},
{  1.880859375,  0.770996094, -0.037597656,  1.007812500,  0.423828125},
{  2.494628906,  1.425292969, -0.098632813,  0.175292969, -0.248535156},
{  1.782226563,  1.565429688,  1.124511719,  0.826660156,  0.632812500},
{  1.418457031, -1.907714844,  0.111816406, -0.583984375, -1.138671875},
{  2.918457031, -1.750488281,  0.393066406,  1.867675781, -1.532226563},
{  1.829101563, -0.295898438,  0.025878906, -0.131347656, -1.611816406},
{  0.295898438,  0.985351563, -0.642578125,  1.984375000,  0.194335938}
};

const real cb_gain[]=
{
   0.515625,  .90234375,  1.579101563,  2.763427734,
  -0.515625, -.90234375, -1.579101563, -2.763427734
};

/* Double Gains: */
const real cb_gain2[]=
{
   1.031250,  1.8046875, 3.158203126,  5.526855468,
  -1.031250, -1.8046875, -3.158203126, -5.526855468
};

/* Midpoints: */
const real cb_gain_mid[]=
{
   0.708984375,  1.240722656,  2.171264649, 0, 
  -0.708984375, -1.240722656, -2.171264649, 0
};

/* Squared Gains: */
const real cb_gain_sq[]=
{
   0.26586914, 0.814224243, 2.493561746, 7.636532841,
   0.26586914, 0.814224243, 2.493561746, 7.636532841
};

const real hw_gain[]=
{
   0.583953857, 0.605346680, 0.627502441, 0.650482178, 0.674316406,
   0.699005127, 0.724578857, 0.751129150, 0.778625488, 0.807128906,
   0.836669922, 0.867309570, 0.899078369, 0.932006836, 0.961486816,
   0.982757568, 0.995635986, 1.000000000, 0.995819092, 0.983154297,
   0.962066650, 0.932769775, 0.895507812, 0.850585938, 0.798400879,
   0.739379883, 0.674072266, 0.602996826, 0.526763916, 0.446014404,
   0.361480713, 0.273834229, 0.183868408, 0.092346191
};

const real hw_percw[]=
{
   0.581085205, 0.591217041, 0.601562500, 0.612091064, 0.622772217,
   0.633666992, 0.644744873, 0.656005859, 0.667480469, 0.679138184,
   0.691009521, 0.703094482, 0.715393066, 0.727874756, 0.740600586,
   0.753570557, 0.766723633, 0.780120850, 0.793762207, 0.807647705,
   0.821746826, 0.836120605, 0.850738525, 0.865600586, 0.880737305,
   0.896148682, 0.911804199, 0.927734375, 0.943939209, 0.960449219,
   0.975372314, 0.986816406, 0.994720459, 0.999084473, 0.999847412,
   0.997070312, 0.990722656, 0.980865479, 0.967468262, 0.950622559,
   0.930389404, 0.906829834, 0.880035400, 0.850097656, 0.817108154,
   0.781219482, 0.742523193, 0.701171875, 0.657348633, 0.611145020,
   0.562774658, 0.512390137, 0.460174561, 0.406311035, 0.351013184,
   0.294433594, 0.236816406, 0.178375244, 0.119262695, 0.059722900
};

const real hw_synth[]=
{
   0.602020264, 0.606384277, 0.610748291, 0.615142822, 0.619598389,
   0.624084473, 0.628570557, 0.633117676, 0.637695312, 0.642272949,
   0.646911621, 0.651580811, 0.656280518, 0.661041260, 0.665802002,
   0.670593262, 0.675445557, 0.680328369, 0.685241699, 0.690185547,
   0.695159912, 0.700164795, 0.705230713, 0.710327148, 0.715454102,
   0.720611572, 0.725830078, 0.731048584, 0.736328125, 0.741638184,
   0.747009277, 0.752380371, 0.757812500, 0.763305664, 0.768798828,
   0.774353027, 0.779937744, 0.785583496, 0.791229248, 0.796936035,
   0.802703857, 0.808502197, 0.814331055, 0.820220947, 0.826141357,
   0.832092285, 0.838104248, 0.844146729, 0.850250244, 0.856384277,
   0.862548828, 0.868774414, 0.875061035, 0.881378174, 0.887725830,
   0.894134521, 0.900604248, 0.907104492, 0.913635254, 0.920227051,
   0.926879883, 0.933563232, 0.940307617, 0.947082520, 0.953918457,
   0.960815430, 0.967742920, 0.974731445, 0.981781006, 0.988861084,
   0.994842529, 0.998565674, 0.999969482, 0.999114990, 0.996002197,
   0.990600586, 0.982910156, 0.973022461, 0.960876465, 0.946533203,
   0.930053711, 0.911437988, 0.890747070, 0.868041992, 0.843322754,
   0.816680908, 0.788208008, 0.757904053, 0.725891113, 0.692199707,
   0.656921387, 0.620178223, 0.582000732, 0.542480469, 0.501739502,
   0.459838867, 0.416900635, 0.373016357, 0.328277588, 0.282775879,
   0.236663818, 0.189971924, 0.142852783, 0.095428467, 0.047760010
};