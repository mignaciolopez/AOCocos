// ---------------------------------------
// Sprite definitions for Interface
// Generated with TexturePacker 4.11.1
//
// https://www.codeandweb.com/texturepacker
// ---------------------------------------

#include "Interface.h"

USING_NS_CC;

namespace TP
{

void Interface::addSpriteFramesToCache()
{
	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	FileUtils* fileUtils = FileUtils::getInstance();

	bool restoreNotify = fileUtils->isPopupNotify();
	fileUtils->setPopupNotify(true); // disable warnings

	int files = 4;
	for (int i = 0; i < files; i++)
	{
		std::string plist = fileUtils->fullPathForFilename("interface-1-" + std::to_string(i) + ".plist");
		std::string png = fileUtils->fullPathForFilename("interface-1-" + std::to_string(i) + ".png");

		if (fileUtils->isFileExist(plist.c_str()) && fileUtils->isFileExist(png.c_str()))
			cache->addSpriteFramesWithFile(plist.c_str(), png.c_str());
		else
		{
			cocos2d::MessageBox("addSpriteFramesToCache() Some of the files could not load.", "[Interface]");
			exit(-2);
		}
	}

	fileUtils->setPopupNotify(restoreNotify); // reset warnings

   /* SpriteFrameCache *cache = SpriteFrameCache::getInstance();

    // load at least one texture
	cache->addSpriteFramesWithFile(Y_INTERFACE_DIR + "Interface-1-0.plist",
		Y_INTERFACE_DIR + "Interface-1-0.png");

    // the number of multipack files varies with the resolution
    // but we don't have information which search paths are set 
    // so we can only try to load the ones we find
    FileUtils *fileUtils = FileUtils::getInstance();
    bool restoreNotify = fileUtils->isPopupNotify();
    fileUtils->setPopupNotify(false); // disable warnings
    if(fileUtils->fullPathForFilename(Y_INTERFACE_DIR + "Interface-1-1.plist").size() > 0)
    {
        cache->addSpriteFramesWithFile(Y_INTERFACE_DIR + "Interface-1-1.plist",
			Y_INTERFACE_DIR + "Interface-1-1.png");
    }
    if(fileUtils->fullPathForFilename(Y_INTERFACE_DIR + "Interface-1-2.plist").size() > 0)
    {
        cache->addSpriteFramesWithFile(Y_INTERFACE_DIR + "Interface-1-2.plist",
			Y_INTERFACE_DIR + "Interface-1-2.png");
    }
    if(fileUtils->fullPathForFilename(Y_INTERFACE_DIR + "Interface-1-3.plist").size() > 0)
    {
        cache->addSpriteFramesWithFile(Y_INTERFACE_DIR + "Interface-1-3.plist",
			Y_INTERFACE_DIR + "Interface-1-3.png");
    }
    fileUtils->setPopupNotify(restoreNotify); // reset warnings*/
};

void Interface::removeSpriteFramesFromCache()
{
	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	if (!cache)
		return;

	FileUtils* fileUtils = FileUtils::getInstance();

	if (!fileUtils)
		return;

	int i = 1;
	int files = 4;
	for (int n = 0; n < files; n++)
	{
		std::string plist = fileUtils->fullPathForFilename("Interface-1-" + std::to_string(i) + ".plist");

		if (fileUtils->isFileExist(plist))
		{
			if (cache->isSpriteFramesWithFileLoaded(plist))
				cache->removeSpriteFramesFromFile(plist);
		}
	}

    /*cache->removeSpriteFramesFromFile(Y_INTERFACE_DIR + "Interface-1-0.plist");
    cache->removeSpriteFramesFromFile(Y_INTERFACE_DIR + "Interface-1-1.plist");
    cache->removeSpriteFramesFromFile(Y_INTERFACE_DIR + "Interface-1-2.plist");
    cache->removeSpriteFramesFromFile(Y_INTERFACE_DIR + "Interface-1-3.plist");*/
};


// ---------------------
// sprite name constants
// ---------------------
const std::string Interface::amigosClick                                 = "AmigosClick.jpg";
const std::string Interface::amigosMenue                                 = "AmigosMenue.jpg";
const std::string Interface::amigosNuevoMensaje                          = "AmigosNuevoMensaje.jpg";
const std::string Interface::amigosRollover                              = "AmigosRollover.jpg";
const std::string Interface::bOtonGrupoClick                             = "BOtonGrupoClick.jpg";
const std::string Interface::botonAceptarCambioContrasenia               = "BotonAceptarCambioContrasenia.jpg";
const std::string Interface::botonAceptarCambioContraseniaClick          = "BotonAceptarCambioContraseniaClick.jpg";
const std::string Interface::botonAceptarCambioContraseniaDisabled       = "BotonAceptarCambioContraseniaDisabled.jpg";
const std::string Interface::botonAceptarCambioContraseniaRollover       = "BotonAceptarCambioContraseniaRollover.jpg";
const std::string Interface::botonAceptarSkills                          = "BotonAceptarSkills.jpg";
const std::string Interface::botonAceptarSkillsClick                     = "BotonAceptarSkillsClick.jpg";
const std::string Interface::botonAceptarSkillsDisabled                  = "BotonAceptarSkillsDisabled.jpg";
const std::string Interface::botonAceptarSkillsRollover                  = "BotonAceptarSkillsRollover.jpg";
const std::string Interface::botonAmigos                                 = "BotonAmigos.jpg";
const std::string Interface::botonAmigosAceptar                          = "BotonAmigosAceptar.jpg";
const std::string Interface::botonAmigosAceptarClick                     = "BotonAmigosAceptarClick.jpg";
const std::string Interface::botonAmigosAceptarRollover                  = "BotonAmigosAceptarRollover.jpg";
const std::string Interface::botonAmigosAceptarSolicitud                 = "BotonAmigosAceptarSolicitud.jpg";
const std::string Interface::botonAmigosAceptarSolicitudClick            = "BotonAmigosAceptarSolicitudClick.jpg";
const std::string Interface::botonAmigosAceptarSolicitudRollover         = "BotonAmigosAceptarSolicitudRollover.jpg";
const std::string Interface::botonAmigosAgregar                          = "BotonAmigosAgregar.jpg";
const std::string Interface::botonAmigosAgregarClick                     = "BotonAmigosAgregarClick.jpg";
const std::string Interface::botonAmigosAgregarRollover                  = "BotonAmigosAgregarRollover.jpg";
const std::string Interface::botonAmigosClick                            = "BotonAmigosClick.jpg";
const std::string Interface::botonAmigosNombre                           = "BotonAmigosNombre.jpg";
const std::string Interface::botonAmigosNombreClick                      = "BotonAmigosNombreClick.jpg";
const std::string Interface::botonAmigosNombreRollover                   = "BotonAmigosNombreRollover.jpg";
const std::string Interface::botonAmigosRechazarSolicitud                = "BotonAmigosRechazarSolicitud.jpg";
const std::string Interface::botonAmigosRechazarSolicitudClick           = "BotonAmigosRechazarSolicitudClick.jpg";
const std::string Interface::botonAmigosRechazarSolicitudRollover        = "BotonAmigosRechazarSolicitudRollover.jpg";
const std::string Interface::botonAmigosRollover                         = "BotonAmigosRollover.jpg";
const std::string Interface::botonAmigosSalas                            = "BotonAmigosSalas.jpg";
const std::string Interface::botonAmigosSalasClick                       = "BotonAmigosSalasClick.jpg";
const std::string Interface::botonAmigosSalasRollover                    = "BotonAmigosSalasRollover.jpg";
const std::string Interface::botonAmigosSolicitudes                      = "BotonAmigosSolicitudes.jpg";
const std::string Interface::botonAmigosSolicitudesClick                 = "BotonAmigosSolicitudesClick.jpg";
const std::string Interface::botonAmigosSolicitudesRollover              = "BotonAmigosSolicitudesRollover.jpg";
const std::string Interface::botonAmigosTac                              = "BotonAmigosTac.jpg";
const std::string Interface::botonAmigosTic                              = "BotonAmigosTic.jpg";
const std::string Interface::botonArmaduras                              = "BotonArmaduras.jpg";
const std::string Interface::botonArmadurasClick                         = "BotonArmadurasClick.jpg";
const std::string Interface::botonArmadurasDisabled                      = "BotonArmadurasDisabled.jpg";
const std::string Interface::botonArmadurasHover                         = "BotonArmadurasHover.jpg";
const std::string Interface::botonArmas                                  = "BotonArmas.jpg";
const std::string Interface::botonArmasClick                             = "BotonArmasClick.jpg";
const std::string Interface::botonArmasDisabled                          = "BotonArmasDisabled.jpg";
const std::string Interface::botonArmasHover                             = "BotonArmasHover.jpg";
const std::string Interface::botonBorrarPersonaje                        = "BotonBorrarPersonaje.jpg";
const std::string Interface::botonBorrarPersonajeClick                   = "BotonBorrarPersonajeClick.jpg";
const std::string Interface::botonBorrarPersonajeDisabled                = "BotonBorrarPersonajeDisabled.jpg";
const std::string Interface::botonBorrarPersonajeRollover                = "BotonBorrarPersonajeRollover.jpg";
const std::string Interface::botonBovedaCuentaCambiar                    = "BotonBovedaCuentaCambiar.jpg";
const std::string Interface::botonBovedaCuentaCambiarClick               = "BotonBovedaCuentaCambiarClick.jpg";
const std::string Interface::botonBovedaCuentaCambiarRollover            = "BotonBovedaCuentaCambiarRollover.jpg";
const std::string Interface::botonBovedaCuentaCambiar_Click              = "BotonBovedaCuentaCambiar_Click.jpg";
const std::string Interface::botonBovedaCuentaCambiar_Hover              = "BotonBovedaCuentaCambiar_Hover.jpg";
const std::string Interface::botonBovedaCuentaIngresar                   = "BotonBovedaCuentaIngresar.jpg";
const std::string Interface::botonBovedaCuentaIngresarClick              = "BotonBovedaCuentaIngresarClick.jpg";
const std::string Interface::botonBovedaCuentaIngresarRollover           = "BotonBovedaCuentaIngresarRollover.jpg";
const std::string Interface::botonBovedaCuentaIngresar_Click             = "BotonBovedaCuentaIngresar_Click.jpg";
const std::string Interface::botonBovedaCuentaIngresar_Hover             = "BotonBovedaCuentaIngresar_Hover.jpg";
const std::string Interface::botonCambiarContrasenia                     = "BotonCambiarContrasenia.jpg";
const std::string Interface::botonCambiarContraseniaClick                = "BotonCambiarContraseniaClick.jpg";
const std::string Interface::botonCambiarContraseniaDisabled             = "BotonCambiarContraseniaDisabled.jpg";
const std::string Interface::botonCambiarContraseniaRollover             = "BotonCambiarContraseniaRollover.jpg";
const std::string Interface::botonCancelarBloqueado                      = "BotonCancelarBloqueado.bmp";
const std::string Interface::botonCerrarForm                             = "BotonCerrarForm.jpg";
const std::string Interface::botonCerrarFormClick                        = "BotonCerrarFormClick.jpg";
const std::string Interface::botonCerrarFormDisabled                     = "BotonCerrarFormDisabled.jpg";
const std::string Interface::botonCerrarFormRollover                     = "BotonCerrarFormRollover.jpg";
const std::string Interface::botonCheck                                  = "BotonCheck.jpg";
const std::string Interface::botonCheckbox                               = "BotonCheckbox.jpg";
const std::string Interface::botonClanActualizar                         = "BotonClanActualizar.jpg";
const std::string Interface::botonClanActualizarClick                    = "BotonClanActualizarClick.jpg";
const std::string Interface::botonClanActualizarDisabled                 = "BotonClanActualizarDisabled.jpg";
const std::string Interface::botonClanActualizarRollover                 = "BotonClanActualizarRollover.jpg";
const std::string Interface::botonClanAlianza                            = "BotonClanAlianza.jpg";
const std::string Interface::botonClanAlianzaClick                       = "BotonClanAlianzaClick.jpg";
const std::string Interface::botonClanAlianzaDisabled                    = "BotonClanAlianzaDisabled.jpg";
const std::string Interface::botonClanAlianzaRollover                    = "BotonClanAlianzaRollover.jpg";
const std::string Interface::botonClanDetalles                           = "BotonClanDetalles.jpg";
const std::string Interface::botonClanDetallesClick                      = "BotonClanDetallesClick.jpg";
const std::string Interface::botonClanDetallesDisabled                   = "BotonClanDetallesDisabled.jpg";
const std::string Interface::botonClanDetallesRollover                   = "BotonClanDetallesRollover.jpg";
const std::string Interface::botonClanEditarCodex                        = "BotonClanEditarCodex.jpg";
const std::string Interface::botonClanEditarCodexAceptar                 = "BotonClanEditarCodexAceptar.jpg";
const std::string Interface::botonClanEditarCodexAceptarClick            = "BotonClanEditarCodexAceptarClick.jpg";
const std::string Interface::botonClanEditarCodexAceptarDisabled         = "BotonClanEditarCodexAceptarDisabled.jpg";
const std::string Interface::botonClanEditarCodexAceptarRollover         = "BotonClanEditarCodexAceptarRollover.jpg";
const std::string Interface::botonClanEditarCodexClick                   = "BotonClanEditarCodexClick.jpg";
const std::string Interface::botonClanEditarCodexDisabled                = "BotonClanEditarCodexDisabled.jpg";
const std::string Interface::botonClanEditarCodexRollover                = "BotonClanEditarCodexRollover.jpg";
const std::string Interface::botonClanEditarUrl                          = "BotonClanEditarUrl.jpg";
const std::string Interface::botonClanEditarUrlClick                     = "BotonClanEditarUrlClick.jpg";
const std::string Interface::botonClanEditarUrlDisabled                  = "BotonClanEditarUrlDisabled.jpg";
const std::string Interface::botonClanEditarUrlRollover                  = "BotonClanEditarUrlRollover.jpg";
const std::string Interface::botonClanEditarWebsiteAceptar               = "BotonClanEditarWebsiteAceptar.jpg";
const std::string Interface::botonClanEditarWebsiteAceptarClick          = "BotonClanEditarWebsiteAceptarClick.jpg";
const std::string Interface::botonClanEditarWebsiteAceptarDisabled       = "BotonClanEditarWebsiteAceptarDisabled.jpg";
const std::string Interface::botonClanEditarWebsiteAceptarRollover       = "BotonClanEditarWebsiteAceptarRollover.jpg";
const std::string Interface::botonClanElecciones                         = "BotonClanElecciones.jpg";
const std::string Interface::botonClanEleccionesClick                    = "BotonClanEleccionesClick.jpg";
const std::string Interface::botonClanEleccionesDisabled                 = "BotonClanEleccionesDisabled.jpg";
const std::string Interface::botonClanEleccionesRollover                 = "BotonClanEleccionesRollover.jpg";
const std::string Interface::botonClanInfoAlianza                        = "BotonClanInfoAlianza.jpg";
const std::string Interface::botonClanInfoAlianzaClick                   = "BotonClanInfoAlianzaClick.jpg";
const std::string Interface::botonClanInfoAlianzaDisabled                = "BotonClanInfoAlianzaDisabled.jpg";
const std::string Interface::botonClanInfoAlianzaRollover                = "BotonClanInfoAlianzaRollover.jpg";
const std::string Interface::botonClanInfoGuerra                         = "BotonClanInfoGuerra.jpg";
const std::string Interface::botonClanInfoGuerraClick                    = "BotonClanInfoGuerraClick.jpg";
const std::string Interface::botonClanInfoGuerraDisabled                 = "BotonClanInfoGuerraDisabled.jpg";
const std::string Interface::botonClanInfoGuerraRollover                 = "BotonClanInfoGuerraRollover.jpg";
const std::string Interface::botonClanInfoPaz                            = "BotonClanInfoPaz.jpg";
const std::string Interface::botonClanInfoPazClick                       = "BotonClanInfoPazClick.jpg";
const std::string Interface::botonClanInfoPazDisabled                    = "BotonClanInfoPazDisabled.jpg";
const std::string Interface::botonClanInfoPazRollover                    = "BotonClanInfoPazRollover.jpg";
const std::string Interface::botonClanInfoSolicitarIngreso               = "BotonClanInfoSolicitarIngreso.jpg";
const std::string Interface::botonClanInfoSolicitarIngresoClick          = "BotonClanInfoSolicitarIngresoClick.jpg";
const std::string Interface::botonClanInfoSolicitarIngresoDisabled       = "BotonClanInfoSolicitarIngresoDisabled.jpg";
const std::string Interface::botonClanInfoSolicitarIngresoRollover       = "BotonClanInfoSolicitarIngresoRollover.jpg";
const std::string Interface::botonClanMemberInfoAceptar                  = "BotonClanMemberInfoAceptar.jpg";
const std::string Interface::botonClanMemberInfoAceptarClick             = "BotonClanMemberInfoAceptarClick.jpg";
const std::string Interface::botonClanMemberInfoAceptarDisabled          = "BotonClanMemberInfoAceptarDisabled.jpg";
const std::string Interface::botonClanMemberInfoAceptarRollover          = "BotonClanMemberInfoAceptarRollover.jpg";
const std::string Interface::botonClanMemberInfoEchar                    = "BotonClanMemberInfoEchar.jpg";
const std::string Interface::botonClanMemberInfoEcharClick               = "BotonClanMemberInfoEcharClick.jpg";
const std::string Interface::botonClanMemberInfoEcharDisabled            = "BotonClanMemberInfoEcharDisabled.jpg";
const std::string Interface::botonClanMemberInfoEcharRollover            = "BotonClanMemberInfoEcharRollover.jpg";
const std::string Interface::botonClanMemberInfoPeticion                 = "BotonClanMemberInfoPeticion.jpg";
const std::string Interface::botonClanMemberInfoPeticionClick            = "BotonClanMemberInfoPeticionClick.jpg";
const std::string Interface::botonClanMemberInfoPeticionDisabled         = "BotonClanMemberInfoPeticionDisabled.jpg";
const std::string Interface::botonClanMemberInfoPeticionRollover         = "BotonClanMemberInfoPeticionRollover.jpg";
const std::string Interface::botonClanMemberInfoRechazar                 = "BotonClanMemberInfoRechazar.jpg";
const std::string Interface::botonClanMemberInfoRechazarClick            = "BotonClanMemberInfoRechazarClick.jpg";
const std::string Interface::botonClanMemberInfoRechazarDisabled         = "BotonClanMemberInfoRechazarDisabled.jpg";
const std::string Interface::botonClanMemberInfoRechazarRollover         = "BotonClanMemberInfoRechazarRollover.jpg";
const std::string Interface::botonClanOfertaAceptar                      = "BotonClanOfertaAceptar.jpg";
const std::string Interface::botonClanOfertaAceptarClick                 = "BotonClanOfertaAceptarClick.jpg";
const std::string Interface::botonClanOfertaAceptarDisabled              = "BotonClanOfertaAceptarDisabled.jpg";
const std::string Interface::botonClanOfertaAceptarRollover              = "BotonClanOfertaAceptarRollover.jpg";
const std::string Interface::botonClanOfertaDetalles                     = "BotonClanOfertaDetalles.jpg";
const std::string Interface::botonClanOfertaDetallesClick                = "BotonClanOfertaDetallesClick.jpg";
const std::string Interface::botonClanOfertaDetallesDisabled             = "BotonClanOfertaDetallesDisabled.jpg";
const std::string Interface::botonClanOfertaDetallesRollover             = "BotonClanOfertaDetallesRollover.jpg";
const std::string Interface::botonClanOfertaRechazar                     = "BotonClanOfertaRechazar.jpg";
const std::string Interface::botonClanOfertaRechazarClick                = "BotonClanOfertaRechazarClick.jpg";
const std::string Interface::botonClanOfertaRechazarDisabled             = "BotonClanOfertaRechazarDisabled.jpg";
const std::string Interface::botonClanOfertaRechazarRollover             = "BotonClanOfertaRechazarRollover.jpg";
const std::string Interface::botonClanPaz                                = "BotonClanPaz.jpg";
const std::string Interface::botonClanPazClick                           = "BotonClanPazClick.jpg";
const std::string Interface::botonClanPazDisabled                        = "BotonClanPazDisabled.jpg";
const std::string Interface::botonClanPazRollover                        = "BotonClanPazRollover.jpg";
const std::string Interface::botonClanSolicitudCerrar                    = "BotonClanSolicitudCerrar.jpg";
const std::string Interface::botonClanSolicitudCerrarClick               = "BotonClanSolicitudCerrarClick.jpg";
const std::string Interface::botonClanSolicitudCerrarDisabled            = "BotonClanSolicitudCerrarDisabled.jpg";
const std::string Interface::botonClanSolicitudCerrarRollover            = "BotonClanSolicitudCerrarRollover.jpg";
const std::string Interface::botonClanSolicitudEnviar                    = "BotonClanSolicitudEnviar.jpg";
const std::string Interface::botonClanSolicitudEnviarClick               = "BotonClanSolicitudEnviarClick.jpg";
const std::string Interface::botonClanSolicitudEnviarDisabled            = "BotonClanSolicitudEnviarDisabled.jpg";
const std::string Interface::botonClanSolicitudEnviarRollover            = "BotonClanSolicitudEnviarRollover.jpg";
const std::string Interface::botonClanVerSolicitudAceptar                = "BotonClanVerSolicitudAceptar.jpg";
const std::string Interface::botonClanVerSolicitudAceptarClick           = "BotonClanVerSolicitudAceptarClick.jpg";
const std::string Interface::botonClanVerSolicitudAceptarDisabled        = "BotonClanVerSolicitudAceptarDisabled.jpg";
const std::string Interface::botonClanVerSolicitudAceptarRollover        = "BotonClanVerSolicitudAceptarRollover.jpg";
const std::string Interface::botonClanes                                 = "BotonClanes.jpg";
const std::string Interface::botonClanesClick                            = "BotonClanesClick.jpg";
const std::string Interface::botonClanesDisabled                         = "BotonClanesDisabled.jpg";
const std::string Interface::botonClanesRollover                         = "BotonClanesRollover.jpg";
const std::string Interface::botonCodigoFuente                           = "BotonCodigoFuente.gif";
const std::string Interface::botonCodigoFuenteClick                      = "BotonCodigoFuenteClick.gif";
const std::string Interface::botonCodigoFuenteRollover                   = "BotonCodigoFuenteRollover.gif";
const std::string Interface::botonComercioComprar                        = "BotonComercioComprar.jpg";
const std::string Interface::botonComercioComprarClick                   = "BotonComercioComprarClick.jpg";
const std::string Interface::botonComercioComprarDisabled                = "BotonComercioComprarDisabled.jpg";
const std::string Interface::botonComercioComprarRollover                = "BotonComercioComprarRollover.jpg";
const std::string Interface::botonComercioSalir                          = "BotonComercioSalir.jpg";
const std::string Interface::botonComercioSalirClick                     = "BotonComercioSalirClick.jpg";
const std::string Interface::botonComercioSalirDisabled                  = "BotonComercioSalirDisabled.jpg";
const std::string Interface::botonComercioSalirRollover                  = "BotonComercioSalirRollover.jpg";
const std::string Interface::botonComercioVender                         = "BotonComercioVender.jpg";
const std::string Interface::botonComercioVenderClick                    = "BotonComercioVenderClick.jpg";
const std::string Interface::botonComercioVenderDisabled                 = "BotonComercioVenderDisabled.jpg";
const std::string Interface::botonComercioVenderRollover                 = "BotonComercioVenderRollover.jpg";
const std::string Interface::botonConectarse                             = "BotonConectarse.jpg";
const std::string Interface::botonConectarseClick                        = "BotonConectarseClick.jpg";
const std::string Interface::botonConectarseDisabled                     = "BotonConectarseDisabled.jpg";
const std::string Interface::botonConectarseRollover                     = "BotonConectarseRollover.gif";
const std::string Interface::botonConfig1                                = "BotonConfig1.jpg";
const std::string Interface::botonConfig1Click                           = "BotonConfig1Click.jpg";
const std::string Interface::botonConfig1Disabled                        = "BotonConfig1Disabled.jpg";
const std::string Interface::botonConfig1Rollover                        = "BotonConfig1Rollover.jpg";
const std::string Interface::botonConfig2                                = "BotonConfig2.jpg";
const std::string Interface::botonConfig2Click                           = "BotonConfig2Click.jpg";
const std::string Interface::botonConfig2Disabled                        = "BotonConfig2Disabled.jpg";
const std::string Interface::botonConfig2Rollover                        = "BotonConfig2Rollover.jpg";
const std::string Interface::botonConfig3                                = "BotonConfig3.jpg";
const std::string Interface::botonConfig3Click                           = "BotonConfig3Click.jpg";
const std::string Interface::botonConfig3Disabled                        = "BotonConfig3Disabled.jpg";
const std::string Interface::botonConfig3Rollover                        = "BotonConfig3Rollover.jpg";
const std::string Interface::botonConfig4                                = "BotonConfig4.jpg";
const std::string Interface::botonConfig4Click                           = "BotonConfig4Click.jpg";
const std::string Interface::botonConfig4Disabled                        = "BotonConfig4Disabled.jpg";
const std::string Interface::botonConfig4Rollover                        = "BotonConfig4Rollover.jpg";
const std::string Interface::botonConfig5                                = "BotonConfig5.jpg";
const std::string Interface::botonConfig5Click                           = "BotonConfig5Click.jpg";
const std::string Interface::botonConfig5Disabled                        = "BotonConfig5Disabled.jpg";
const std::string Interface::botonConfig5Rollover                        = "BotonConfig5Rollover.jpg";
const std::string Interface::botonConfig6                                = "BotonConfig6.jpg";
const std::string Interface::botonConfig6Click                           = "BotonConfig6Click.jpg";
const std::string Interface::botonConfig6Disabled                        = "BotonConfig6Disabled.jpg";
const std::string Interface::botonConfig6Rollover                        = "BotonConfig6Rollover.jpg";
const std::string Interface::botonConfig7                                = "BotonConfig7.jpg";
const std::string Interface::botonConfig7Click                           = "BotonConfig7Click.jpg";
const std::string Interface::botonConfig7Disabled                        = "BotonConfig7Disabled.jpg";
const std::string Interface::botonConfig7Rollover                        = "BotonConfig7Rollover.jpg";
const std::string Interface::botonConfig8                                = "BotonConfig8.jpg";
const std::string Interface::botonConfig8Click                           = "BotonConfig8Click.jpg";
const std::string Interface::botonConfig8Disabled                        = "BotonConfig8Disabled.jpg";
const std::string Interface::botonConfig8Rollover                        = "BotonConfig8Rollover.jpg";
const std::string Interface::botonConfig9                                = "BotonConfig9.jpg";
const std::string Interface::botonConfig9Click                           = "BotonConfig9Click.jpg";
const std::string Interface::botonConfig9Disabled                        = "BotonConfig9Disabled.jpg";
const std::string Interface::botonConfig9Rollover                        = "BotonConfig9Rollover.jpg";
const std::string Interface::botonConfigCargarDefault                    = "BotonConfigCargarDefault.jpg";
const std::string Interface::botonConfigCargarDefaultClick               = "BotonConfigCargarDefaultClick.jpg";
const std::string Interface::botonConfigCargarDefaultRollover            = "BotonConfigCargarDefaultRollover.jpg";
const std::string Interface::botonConfigDefault                          = "BotonConfigDefault.jpg";
const std::string Interface::botonConfigDefaultClick                     = "BotonConfigDefaultClick.jpg";
const std::string Interface::botonConfigDefaultDisabled                  = "BotonConfigDefaultDisabled.jpg";
const std::string Interface::botonConfigDefaultRollover                  = "BotonConfigDefaultRollover.jpg";
const std::string Interface::botonConfigGuardar                          = "BotonConfigGuardar.jpg";
const std::string Interface::botonConfigGuardarClick                     = "BotonConfigGuardarClick.jpg";
const std::string Interface::botonConfigGuardarRollover                  = "BotonConfigGuardarRollover.jpg";
const std::string Interface::botonConfigurarConsolaGuardar               = "BotonConfigurarConsolaGuardar.jpg";
const std::string Interface::botonConfigurarConsolaGuardarClick          = "BotonConfigurarConsolaGuardarClick.jpg";
const std::string Interface::botonConfigurarConsolaGuardarDisabled       = "BotonConfigurarConsolaGuardarDisabled.jpg";
const std::string Interface::botonConfigurarConsolaGuardarRollover       = "BotonConfigurarConsolaGuardarRollover.jpg";
const std::string Interface::botonConfigurarConsolaSalir                 = "BotonConfigurarConsolaSalir.jpg";
const std::string Interface::botonConfigurarConsolaSalirClick            = "BotonConfigurarConsolaSalirClick.jpg";
const std::string Interface::botonConfigurarConsolaSalirDisabled         = "BotonConfigurarConsolaSalirDisabled.jpg";
const std::string Interface::botonConfigurarConsolaSalirRollover         = "BotonConfigurarConsolaSalirRollover.jpg";
const std::string Interface::botonConfirmarBloqueado                     = "BotonConfirmarBloqueado.bmp";
const std::string Interface::botonConstruir                              = "BotonConstruir.jpg";
const std::string Interface::botonConstruirClick                         = "BotonConstruirClick.jpg";
const std::string Interface::botonConstruirDisabled                      = "BotonConstruirDisabled.jpg";
const std::string Interface::botonConstruirHover                         = "BotonConstruirHover.jpg";
const std::string Interface::botonCrafteoSalir                           = "BotonCrafteoSalir.jpg";
const std::string Interface::botonCrafteoSalirClick                      = "BotonCrafteoSalirClick.jpg";
const std::string Interface::botonCrafteoSalirDisabled                   = "BotonCrafteoSalirDisabled.jpg";
const std::string Interface::botonCrafteoSalirRollover                   = "BotonCrafteoSalirRollover.jpg";
const std::string Interface::botonCrearCuenta                            = "BotonCrearCuenta.jpg";
const std::string Interface::botonCrearCuentaClick                       = "BotonCrearCuentaClick.jpg";
const std::string Interface::botonCrearCuentaDisabled                    = "BotonCrearCuentaDisabled.gif";
const std::string Interface::botonCrearCuentaRollover                    = "BotonCrearCuentaRollover.gif";
const std::string Interface::botonCrearPersonaje                         = "BotonCrearPersonaje.gif";
const std::string Interface::botonCrearPersonajeClick                    = "BotonCrearPersonajeClick.jpg";
const std::string Interface::botonCrearPersonajeDisabled                 = "BotonCrearPersonajeDisabled.jpg";
const std::string Interface::botonCrearPersonajeRegresar                 = "BotonCrearPersonajeRegresar.jpg";
const std::string Interface::botonCrearPersonajeRegresarClick            = "BotonCrearPersonajeRegresarClick.jpg";
const std::string Interface::botonCrearPersonajeRegresarDisabled         = "BotonCrearPersonajeRegresarDisabled.jpg";
const std::string Interface::botonCrearPersonajeRegresarRollover         = "BotonCrearPersonajeRegresarRollover.jpg";
const std::string Interface::botonCrearPersonajeRollover                 = "BotonCrearPersonajeRollover.jpg";
const std::string Interface::botonCrearPersonajes                        = "BotonCrearPersonajes.gif";
const std::string Interface::botonCrearPersonajesClick                   = "BotonCrearPersonajesClick.gif";
const std::string Interface::botonCrearPersonajesDisabled                = "BotonCrearPersonajesDisabled.gif";
const std::string Interface::botonCrearPersonajesRegresar                = "BotonCrearPersonajesRegresar.jpg";
const std::string Interface::botonCrearPersonajesRegresarClick           = "BotonCrearPersonajesRegresarClick.jpg";
const std::string Interface::botonCrearPersonajesRegresarDisabled        = "BotonCrearPersonajesRegresarDisabled.jpg";
const std::string Interface::botonCrearPersonajesRegresarRollover        = "BotonCrearPersonajesRegresarRollover.jpg";
const std::string Interface::botonCrearPersonajesRollover                = "BotonCrearPersonajesRollover.gif";
const std::string Interface::botonCruzSalir                              = "BotonCruzSalir.jpg";
const std::string Interface::botonCruzSalirClick                         = "BotonCruzSalirClick.jpg";
const std::string Interface::botonCruzSalirDisabled                      = "BotonCruzSalirDisabled.jpg";
const std::string Interface::botonCruzSalirRollover                      = "BotonCruzSalirRollover.jpg";
const std::string Interface::botonDeleteCharCancelar                     = "BotonDeleteCharCancelar.jpg";
const std::string Interface::botonDeleteCharCancelarClick                = "BotonDeleteCharCancelarClick.jpg";
const std::string Interface::botonDeleteCharCancelarDisabled             = "BotonDeleteCharCancelarDisabled.jpg";
const std::string Interface::botonDeleteCharCancelarRollover             = "BotonDeleteCharCancelarRollover.jpg";
const std::string Interface::botonDeleteCharConfirmar                    = "BotonDeleteCharConfirmar.jpg";
const std::string Interface::botonDeleteCharConfirmarClick               = "BotonDeleteCharConfirmarClick.jpg";
const std::string Interface::botonDeleteCharConfirmarDisabled            = "BotonDeleteCharConfirmarDisabled.jpg";
const std::string Interface::botonDeleteCharConfirmarRollover            = "BotonDeleteCharConfirmarRollover.jpg";
const std::string Interface::botonDialogosAplicar                        = "BotonDialogosAplicar.jpg";
const std::string Interface::botonDialogosAplicarClick                   = "BotonDialogosAplicarClick.jpg";
const std::string Interface::botonDialogosAplicarDisabled                = "BotonDialogosAplicarDisabled.jpg";
const std::string Interface::botonDialogosAplicarRollover                = "BotonDialogosAplicarRollover.jpg";
const std::string Interface::botonDialogosDefecto                        = "BotonDialogosDefecto.jpg";
const std::string Interface::botonDialogosDefectoClick                   = "BotonDialogosDefectoClick.jpg";
const std::string Interface::botonDialogosDefectoDisabled                = "BotonDialogosDefectoDisabled.jpg";
const std::string Interface::botonDialogosDefectoRollover                = "BotonDialogosDefectoRollover.jpg";
const std::string Interface::botonDialogosSalir                          = "BotonDialogosSalir.jpg";
const std::string Interface::botonDialogosSalirClick                     = "BotonDialogosSalirClick.jpg";
const std::string Interface::botonDialogosSalirDisabled                  = "BotonDialogosSalirDisabled.jpg";
const std::string Interface::botonDialogosSalirRollover                  = "BotonDialogosSalirRollover.jpg";
const std::string Interface::botonDialogosTodoDefecto                    = "BotonDialogosTodoDefecto.jpg";
const std::string Interface::botonDialogosTodoDefectoClick               = "BotonDialogosTodoDefectoClick.jpg";
const std::string Interface::botonDialogosTodoDefectoDisabled            = "BotonDialogosTodoDefectoDisabled.jpg";
const std::string Interface::botonDialogosTodoDefectoRollover            = "BotonDialogosTodoDefectoRollover.jpg";
const std::string Interface::botonDuelo1v1                               = "BotonDuelo1v1.jpg";
const std::string Interface::botonDuelo1v1Click                          = "BotonDuelo1v1Click.jpg";
const std::string Interface::botonDuelo1v1Rollover                       = "BotonDuelo1v1Rollover.jpg";
const std::string Interface::botonDuelo2v2                               = "BotonDuelo2v2.jpg";
const std::string Interface::botonDuelo2v2Click                          = "BotonDuelo2v2Click.jpg";
const std::string Interface::botonDuelo2v2Rollover                       = "BotonDuelo2v2Rollover.jpg";
const std::string Interface::botonDuelo3v3                               = "BotonDuelo3v3.jpg";
const std::string Interface::botonDuelo3v3Click                          = "BotonDuelo3v3Click.jpg";
const std::string Interface::botonDuelo3v3Rollover                       = "BotonDuelo3v3Rollover.jpg";
const std::string Interface::botonDuelo4v4                               = "BotonDuelo4v4.jpg";
const std::string Interface::botonDuelo4v4Click                          = "BotonDuelo4v4Click.jpg";
const std::string Interface::botonDuelo4v4Rollover                       = "BotonDuelo4v4Rollover.jpg";
const std::string Interface::botonDueloAmigosTac                         = "BotonDueloAmigosTac.jpg";
const std::string Interface::botonDueloAmigosTic                         = "BotonDueloAmigosTic.jpg";
const std::string Interface::botonDueloCancelarEspera                    = "BotonDueloCancelarEspera.jpg";
const std::string Interface::botonDueloCancelarEsperaClick               = "BotonDueloCancelarEsperaClick.jpg";
const std::string Interface::botonDueloCancelarEsperaRollover            = "BotonDueloCancelarEsperaRollover.jpg";
const std::string Interface::botonEntrarPersonaje                        = "BotonEntrarPersonaje.jpg";
const std::string Interface::botonEntrarPersonajeClick                   = "BotonEntrarPersonajeClick.jpg";
const std::string Interface::botonEntrarPersonajeDisabled                = "BotonEntrarPersonajeDisabled.jpg";
const std::string Interface::botonEntrarPersonajeRollover                = "BotonEntrarPersonajeRollover.jpg";
const std::string Interface::botonEnviarDuelo                            = "BotonEnviarDuelo.jpg";
const std::string Interface::botonEnviarDueloClick                       = "BotonEnviarDueloClick.jpg";
const std::string Interface::botonEnviarDueloRollover                    = "BotonEnviarDueloRollover.jpg";
const std::string Interface::botonEstadisticas                           = "BotonEstadisticas.jpg";
const std::string Interface::botonEstadisticasClick                      = "BotonEstadisticasClick.jpg";
const std::string Interface::botonEstadisticasDisabled                   = "BotonEstadisticasDisabled.jpg";
const std::string Interface::botonEstadisticasRollover                   = "BotonEstadisticasRollover.jpg";
const std::string Interface::botonEstadisticasSalir                      = "BotonEstadisticasSalir.jpg";
const std::string Interface::botonEstadisticasSalirClick                 = "BotonEstadisticasSalirClick.jpg";
const std::string Interface::botonEstadisticasSalirDisabled              = "BotonEstadisticasSalirDisabled.jpg";
const std::string Interface::botonEstadisticasSalirRollover              = "BotonEstadisticasSalirRollover.jpg";
const std::string Interface::botonFlechaDerecha                          = "BotonFlechaDerecha.gif";
const std::string Interface::botonFlechaDerechaRollover                  = "BotonFlechaDerechaRollover.gif";
const std::string Interface::botonFlechaIzquierda                        = "BotonFlechaIzquierda.gif";
const std::string Interface::botonFlechaIzquierdaRollover                = "BotonFlechaIzquierdaRollover.gif";
const std::string Interface::botonGrupo                                  = "BotonGrupo.jpg";
const std::string Interface::botonGrupoDisabled                          = "BotonGrupoDisabled.jpg";
const std::string Interface::botonGrupoNuevoMensaje                      = "BotonGrupoNuevoMensaje.jpg";
const std::string Interface::botonGrupoRollover                          = "BotonGrupoRollover.jpg";
const std::string Interface::botonItems                                  = "BotonItems.jpg";
const std::string Interface::botonItemsClick                             = "BotonItemsClick.jpg";
const std::string Interface::botonItemsDisabled                          = "BotonItemsDisabled.jpg";
const std::string Interface::botonItemsHover                             = "BotonItemsHover.jpg";
const std::string Interface::botonLiberarMascotas                        = "BotonLiberarMascotas.png";
const std::string Interface::botonLiberarMascotasClick                   = "BotonLiberarMascotasClick.png";
const std::string Interface::botonLiberarMascotasDisabled                = "BotonLiberarMascotasDisabled.png";
const std::string Interface::botonLiberarMascotasRollover                = "BotonLiberarMascotasRollover.png";
const std::string Interface::botonListaClanesDetalle                     = "BotonListaClanesDetalle.jpg";
const std::string Interface::botonListaClanesDetalleClick                = "BotonListaClanesDetalleClick.jpg";
const std::string Interface::botonListaClanesDetalleRollover             = "BotonListaClanesDetalleRollover.jpg";
const std::string Interface::botonManual                                 = "BotonManual.gif";
const std::string Interface::botonManualClick                            = "BotonManualClick.gif";
const std::string Interface::botonManualRollover                         = "BotonManualRollover.gif";
const std::string Interface::botonMapa                                   = "BotonMapa.jpg";
const std::string Interface::botonMapaClick                              = "BotonMapaClick.jpg";
const std::string Interface::botonMapaDisabled                           = "BotonMapaDisabled.jpg";
const std::string Interface::botonMapaDungeons                           = "BotonMapaDungeons.jpg";
const std::string Interface::botonMapaDungeonsClick                      = "BotonMapaDungeonsClick.jpg";
const std::string Interface::botonMapaDungeonsRollover                   = "BotonMapaDungeonsRollover.jpg";
const std::string Interface::botonMapaMundo                              = "BotonMapaMundo.jpg";
const std::string Interface::botonMapaMundoClick                         = "BotonMapaMundoClick.jpg";
const std::string Interface::botonMapaMundoRollover                      = "BotonMapaMundoRollover.jpg";
const std::string Interface::botonMapaRollover                           = "BotonMapaRollover.jpg";
const std::string Interface::botonMasSkills                              = "BotonMasSkills.jpg";
const std::string Interface::botonMasSkillsClick                         = "BotonMasSkillsClick.jpg";
const std::string Interface::botonMasSkillsDisabled                      = "BotonMasSkillsDisabled.jpg";
const std::string Interface::botonMasSkillsRollover                      = "BotonMasSkillsRollover.jpg";
const std::string Interface::botonMascotaSalir                           = "BotonMascotaSalir.jpg";
const std::string Interface::botonMascotaSalirClick                      = "BotonMascotaSalirClick.jpg";
const std::string Interface::botonMascotaSalirDisabled                   = "BotonMascotaSalirDisabled.jpg";
const std::string Interface::botonMascotaSalirRollover                   = "BotonMascotaSalirRollover.jpg";
const std::string Interface::botonMascotasLiberar                        = "BotonMascotasLiberar.jpg";
const std::string Interface::botonMascotasLiberarClick                   = "BotonMascotasLiberarClick.jpg";
const std::string Interface::botonMascotasLiberarDisabled                = "BotonMascotasLiberarDisabled.jpg";
const std::string Interface::botonMascotasLiberarRollover                = "BotonMascotasLiberarRollover.jpg";
const std::string Interface::botonMascotasSeleccionar                    = "BotonMascotasSeleccionar.jpg";
const std::string Interface::botonMascotasSeleccionarClick               = "BotonMascotasSeleccionarClick.jpg";
const std::string Interface::botonMascotasSeleccionarDisabled            = "BotonMascotasSeleccionarDisabled.jpg";
const std::string Interface::botonMascotasSeleccionarRollover            = "BotonMascotasSeleccionarRollover.jpg";
const std::string Interface::botonMejorar                                = "BotonMejorar.jpg";
const std::string Interface::botonMejorarClick                           = "BotonMejorarClick.jpg";
const std::string Interface::botonMejorarDisabled                        = "BotonMejorarDisabled.jpg";
const std::string Interface::botonMejorarHover                           = "BotonMejorarHover.jpg";
const std::string Interface::botonMenosSkills                            = "BotonMenosSkills.jpg";
const std::string Interface::botonMenosSkillsClick                       = "BotonMenosSkillsClick.jpg";
const std::string Interface::botonMenosSkillsDisabled                    = "BotonMenosSkillsDisabled.jpg";
const std::string Interface::botonMenosSkillsRollover                    = "BotonMenosSkillsRollover.jpg";
const std::string Interface::botonMensajesGuardar                        = "BotonMensajesGuardar.jpg";
const std::string Interface::botonMensajesGuardarClick                   = "BotonMensajesGuardarClick.jpg";
const std::string Interface::botonMensajesGuardarDisabled                = "BotonMensajesGuardarDisabled.jpg";
const std::string Interface::botonMensajesGuardarRollover                = "BotonMensajesGuardarRollover.jpg";
const std::string Interface::botonMensajesSalir                          = "BotonMensajesSalir.jpg";
const std::string Interface::botonMensajesSalirClick                     = "BotonMensajesSalirClick.jpg";
const std::string Interface::botonMensajesSalirDisabled                  = "BotonMensajesSalirDisabled.jpg";
const std::string Interface::botonMensajesSalirRollover                  = "BotonMensajesSalirRollover.jpg";
const std::string Interface::botonMoverHechiAbajo                        = "BotonMoverHechiAbajo.jpg";
const std::string Interface::botonMoverHechiAbajoClick                   = "BotonMoverHechiAbajoClick.jpg";
const std::string Interface::botonMoverHechiAbajoRollover                = "BotonMoverHechiAbajoRollover.jpg";
const std::string Interface::botonMoverHechiArriba                       = "BotonMoverHechiArriba.jpg";
const std::string Interface::botonMoverHechiArribaClick                  = "BotonMoverHechiArribaClick.jpg";
const std::string Interface::botonMoverHechiArribaRollover               = "BotonMoverHechiArribaRollover.jpg";
const std::string Interface::botonNoticiasClanAceptar                    = "BotonNoticiasClanAceptar.jpg";
const std::string Interface::botonNoticiasClanAceptarClick               = "BotonNoticiasClanAceptarClick.jpg";
const std::string Interface::botonNoticiasClanAceptarDisabled            = "BotonNoticiasClanAceptarDisabled.jpg";
const std::string Interface::botonNoticiasClanAceptarRollover            = "BotonNoticiasClanAceptarRollover.jpg";
const std::string Interface::botonOpciones                               = "BotonOpciones.jpg";
const std::string Interface::botonOpcionesCambiarContrasenia             = "BotonOpcionesCambiarContrasenia.jpg";
const std::string Interface::botonOpcionesCambiarContraseniaClick        = "BotonOpcionesCambiarContraseniaClick.jpg";
const std::string Interface::botonOpcionesCambiarContraseniaDisabled     = "BotonOpcionesCambiarContraseniaDisabled.jpg";
const std::string Interface::botonOpcionesCambiarContraseniaRollover     = "BotonOpcionesCambiarContraseniaRollover.jpg";
const std::string Interface::botonOpcionesClick                          = "BotonOpcionesClick.jpg";
const std::string Interface::botonOpcionesConfigurarTeclas               = "BotonOpcionesConfigurarTeclas.jpg";
const std::string Interface::botonOpcionesConfigurarTeclasClick          = "BotonOpcionesConfigurarTeclasClick.jpg";
const std::string Interface::botonOpcionesConfigurarTeclasDisabled       = "BotonOpcionesConfigurarTeclasDisabled.jpg";
const std::string Interface::botonOpcionesConfigurarTeclasRollover       = "BotonOpcionesConfigurarTeclasRollover.jpg";
const std::string Interface::botonOpcionesDisabled                       = "BotonOpcionesDisabled.jpg";
const std::string Interface::botonOpcionesManual                         = "BotonOpcionesManual.jpg";
const std::string Interface::botonOpcionesManualClick                    = "BotonOpcionesManualClick.jpg";
const std::string Interface::botonOpcionesManualDisabled                 = "BotonOpcionesManualDisabled.jpg";
const std::string Interface::botonOpcionesManualRollover                 = "BotonOpcionesManualRollover.jpg";
const std::string Interface::botonOpcionesMapa                           = "BotonOpcionesMapa.jpg";
const std::string Interface::botonOpcionesMapaClick                      = "BotonOpcionesMapaClick.jpg";
const std::string Interface::botonOpcionesMapaDisabled                   = "BotonOpcionesMapaDisabled.jpg";
const std::string Interface::botonOpcionesMapaRollover                   = "BotonOpcionesMapaRollover.jpg";
const std::string Interface::botonOpcionesMensajesPersonalizados         = "BotonOpcionesMensajesPersonalizados.jpg";
const std::string Interface::botonOpcionesMensajesPersonalizadosClick    = "BotonOpcionesMensajesPersonalizadosClick.jpg";
const std::string Interface::botonOpcionesMensajesPersonalizadosDisabled = "BotonOpcionesMensajesPersonalizadosDisabled.jpg";
const std::string Interface::botonOpcionesMensajesPersonalizadosRollover = "BotonOpcionesMensajesPersonalizadosRollover.jpg";
const std::string Interface::botonOpcionesRadio                          = "BotonOpcionesRadio.jpg";
const std::string Interface::botonOpcionesRadioClick                     = "BotonOpcionesRadioClick.jpg";
const std::string Interface::botonOpcionesRadioDisabled                  = "BotonOpcionesRadioDisabled.jpg";
const std::string Interface::botonOpcionesRadioRollover                  = "BotonOpcionesRadioRollover.jpg";
const std::string Interface::botonOpcionesRollover                       = "BotonOpcionesRollover.jpg";
const std::string Interface::botonOpcionesSalir                          = "BotonOpcionesSalir.jpg";
const std::string Interface::botonOpcionesSalirClick                     = "BotonOpcionesSalirClick.jpg";
const std::string Interface::botonOpcionesSalirDisabled                  = "BotonOpcionesSalirDisabled.jpg";
const std::string Interface::botonOpcionesSalirRollover                  = "BotonOpcionesSalirRollover.jpg";
const std::string Interface::botonOpcionesSoporte                        = "BotonOpcionesSoporte.jpg";
const std::string Interface::botonOpcionesSoporteClick                   = "BotonOpcionesSoporteClick.jpg";
const std::string Interface::botonOpcionesSoporteDisabled                = "BotonOpcionesSoporteDisabled.jpg";
const std::string Interface::botonOpcionesSoporteRollover                = "BotonOpcionesSoporteRollover.jpg";
const std::string Interface::botonOpcionesTutorial                       = "BotonOpcionesTutorial.jpg";
const std::string Interface::botonOpcionesTutorialClick                  = "BotonOpcionesTutorialClick.jpg";
const std::string Interface::botonOpcionesTutorialDisabled               = "BotonOpcionesTutorialDisabled.jpg";
const std::string Interface::botonOpcionesTutorialRollover               = "BotonOpcionesTutorialRollover.jpg";
const std::string Interface::botonRecuperarCuenta                        = "BotonRecuperarCuenta.jpg";
const std::string Interface::botonRecuperarCuentaClick                   = "BotonRecuperarCuentaClick.jpg";
const std::string Interface::botonRecuperarCuentaDisabled                = "BotonRecuperarCuentaDisabled.jpg";
const std::string Interface::botonRecuperarCuentaRollover                = "BotonRecuperarCuentaRollover.jpg";
const std::string Interface::botonReglamento                             = "BotonReglamento.gif";
const std::string Interface::botonReglamentoClick                        = "BotonReglamentoClick.gif";
const std::string Interface::botonReglamentoRollover                     = "BotonReglamentoRollover.gif";
const std::string Interface::botonResolucionNo                           = "BotonResolucionNo.jpg";
const std::string Interface::botonResolucionNoClick                      = "BotonResolucionNoClick.jpg";
const std::string Interface::botonResolucionNoDisabled                   = "BotonResolucionNoDisabled.jpg";
const std::string Interface::botonResolucionNoRollover                   = "BotonResolucionNoRollover.jpg";
const std::string Interface::botonResolucionSi                           = "BotonResolucionSi.jpg";
const std::string Interface::botonResolucionSiClick                      = "BotonResolucionSiClick.jpg";
const std::string Interface::botonResolucionSiDisabled                   = "BotonResolucionSiDisabled.jpg";
const std::string Interface::botonResolucionSiRollover                   = "BotonResolucionSiRollover.jpg";
const std::string Interface::botonSalir                                  = "BotonSalir.jpg";
const std::string Interface::botonSalirClick                             = "BotonSalirClick.jpg";
const std::string Interface::botonSalirClickConnect                      = "BotonSalirClickConnect.gif";
const std::string Interface::botonSalirConnect                           = "BotonSalirConnect.gif";
const std::string Interface::botonSalirDisabled                          = "BotonSalirDisabled.jpg";
const std::string Interface::botonSalirMascotas                          = "BotonSalirMascotas.jpg";
const std::string Interface::botonSalirMascotasClick                     = "BotonSalirMascotasClick.jpg";
const std::string Interface::botonSalirMascotasDisabled                  = "BotonSalirMascotasDisabled.jpg";
const std::string Interface::botonSalirMascotasRollover                  = "BotonSalirMascotasRollover.jpg";
const std::string Interface::botonSalirRollover                          = "BotonSalirRollover.jpg";
const std::string Interface::botonSalirSkills                            = "BotonSalirSkills.jpg";
const std::string Interface::botonSalirSkillsClick                       = "BotonSalirSkillsClick.jpg";
const std::string Interface::botonSalirSkillsDisabled                    = "BotonSalirSkillsDisabled.jpg";
const std::string Interface::botonSalirSkillsRollover                    = "BotonSalirSkillsRollover.jpg";
const std::string Interface::botonSeleccionarMascotas                    = "BotonSeleccionarMascotas.png";
const std::string Interface::botonSeleccionarMascotasClick               = "BotonSeleccionarMascotasClick.png";
const std::string Interface::botonSeleccionarMascotasDisabled            = "BotonSeleccionarMascotasDisabled.png";
const std::string Interface::botonSeleccionarMascotasRollover            = "BotonSeleccionarMascotasRollover.png";
const std::string Interface::botonSkill                                  = "BotonSkill.jpg";
const std::string Interface::botonSkillClick                             = "BotonSkillClick.jpg";
const std::string Interface::botonSkillDisabled                          = "BotonSkillDisabled.jpg";
const std::string Interface::botonSkillRollover                          = "BotonSkillRollover.jpg";
const std::string Interface::botonSkillsAceptar                          = "BotonSkillsAceptar.jpg";
const std::string Interface::botonSkillsAceptarClick                     = "BotonSkillsAceptarClick.jpg";
const std::string Interface::botonSkillsAceptarDisabled                  = "BotonSkillsAceptarDisabled.jpg";
const std::string Interface::botonSkillsAceptarRollover                  = "BotonSkillsAceptarRollover.jpg";
const std::string Interface::botonSkillsMas                              = "BotonSkillsMas.jpg";
const std::string Interface::botonSkillsMasClick                         = "BotonSkillsMasClick.jpg";
const std::string Interface::botonSkillsMasDisabled                      = "BotonSkillsMasDisabled.jpg";
const std::string Interface::botonSkillsMasRollover                      = "BotonSkillsMasRollover.jpg";
const std::string Interface::botonSkillsMenos                            = "BotonSkillsMenos.jpg";
const std::string Interface::botonSkillsMenosClick                       = "BotonSkillsMenosClick.jpg";
const std::string Interface::botonSkillsMenosDisabled                    = "BotonSkillsMenosDisabled.jpg";
const std::string Interface::botonSkillsMenosRollover                    = "BotonSkillsMenosRollover.jpg";
const std::string Interface::botonSkillsSalir                            = "BotonSkillsSalir.jpg";
const std::string Interface::botonSkillsSalirClick                       = "BotonSkillsSalirClick.jpg";
const std::string Interface::botonSkillsSalirDisabled                    = "BotonSkillsSalirDisabled.jpg";
const std::string Interface::botonSkillsSalirRollover                    = "BotonSkillsSalirRollover.jpg";
const std::string Interface::botonTirar                                  = "BotonTirar.jpg";
const std::string Interface::botonTirarClick                             = "BotonTirarClick.jpg";
const std::string Interface::botonTirarDisabled                          = "BotonTirarDisabled.jpg";
const std::string Interface::botonTirarRollover                          = "BotonTirarRollover.jpg";
const std::string Interface::botonTirarTodo                              = "BotonTirarTodo.jpg";
const std::string Interface::botonTirarTodoClick                         = "BotonTirarTodoClick.jpg";
const std::string Interface::botonTirarTodoDisabled                      = "BotonTirarTodoDisabled.jpg";
const std::string Interface::botonTirarTodoRollover                      = "BotonTirarTodoRollover.jpg";
const std::string Interface::botonTutorialAnterior                       = "BotonTutorialAnterior.jpg";
const std::string Interface::botonTutorialAnteriorClick                  = "BotonTutorialAnteriorClick.jpg";
const std::string Interface::botonTutorialAnteriorDisabled               = "BotonTutorialAnteriorDisabled.jpg";
const std::string Interface::botonTutorialAnteriorRollover               = "BotonTutorialAnteriorRollover.jpg";
const std::string Interface::botonTutorialSiguiente                      = "BotonTutorialSiguiente.jpg";
const std::string Interface::botonTutorialSiguienteClick                 = "BotonTutorialSiguienteClick.jpg";
const std::string Interface::botonTutorialSiguienteDisabled              = "BotonTutorialSiguienteDisabled.jpg";
const std::string Interface::botonTutorialSiguienteRollover              = "BotonTutorialSiguienteRollover.jpg";
const std::string Interface::cajaMascota                                 = "CajaMascota.jpg";
const std::string Interface::cajaMascotaClick                            = "CajaMascotaClick.jpg";
const std::string Interface::cajaMascotaDisabled                         = "CajaMascotaDisabled.jpg";
const std::string Interface::cajaMascotaRollover                         = "CajaMascotaRollover.jpg";
const std::string Interface::centroHechizos                              = "CentroHechizos.jpg";
const std::string Interface::centroInventario                            = "CentroInventario.jpg";
const std::string Interface::estrellaBrillante                           = "EstrellaBrillante.jpg";
const std::string Interface::estrellaMitad                               = "EstrellaMitad.jpg";
const std::string Interface::estrellaSimple                              = "EstrellaSimple.jpg";
const std::string Interface::iconConfigDisabled                          = "IconConfigDisabled.gif";
const std::string Interface::iconConfigEnabled                           = "IconConfigEnabled.gif";
const std::string Interface::marcoAmigoOffline                           = "MarcoAmigoOffline.jpg";
const std::string Interface::marcoAmigoOnline                            = "MarcoAmigoOnline.jpg";
const std::string Interface::marcoAmigoSala                              = "MarcoAmigoSala.jpg";
const std::string Interface::marcoAmigoSalaNuevoMensaje                  = "MarcoAmigoSalaNuevoMensaje.jpg";
const std::string Interface::marcoAmigoSalaSeleccionada                  = "MarcoAmigoSalaSeleccionada.jpg";
const std::string Interface::marcoItemsCrafteo                           = "MarcoItemsCrafteo.jpg";
const std::string Interface::minusDisabled                               = "MinusDisabled.bmp";
const std::string Interface::minusEnabled                                = "MinusEnabled.bmp";
const std::string Interface::noMostrarTutorial                           = "NoMostrarTutorial.jpg";
const std::string Interface::originArghal                                = "OriginArghal.bmp";
const std::string Interface::originBanderbill                            = "OriginBanderbill.bmp";
const std::string Interface::originLindos                                = "OriginLindos.bmp";
const std::string Interface::originNix                                   = "OriginNix.bmp";
const std::string Interface::originUllathorpe                            = "OriginUllathorpe.bmp";
const std::string Interface::partyClick                                  = "PartyClick.jpg";
const std::string Interface::partyMenue                                  = "PartyMenue.jpg";
const std::string Interface::partyRollover                               = "PartyRollover.jpg";
const std::string Interface::pestaniaAccionesApagado                     = "PestaniaAccionesApagado.jpg";
const std::string Interface::pestaniaAccionesMensajesNuevos              = "PestaniaAccionesMensajesNuevos.jpg";
const std::string Interface::pestaniaAccionesRollover                    = "PestaniaAccionesRollover.jpg";
const std::string Interface::pestaniaAccionesSeleccionado                = "PestaniaAccionesSeleccionado.jpg";
const std::string Interface::pestaniaAgrupacionesApagado                 = "PestaniaAgrupacionesApagado.jpg";
const std::string Interface::pestaniaAgrupacionesMensajesNuevos          = "PestaniaAgrupacionesMensajesNuevos.jpg";
const std::string Interface::pestaniaAgrupacionesRollover                = "PestaniaAgrupacionesRollover.jpg";
const std::string Interface::pestaniaAgrupacionesSeleccionado            = "PestaniaAgrupacionesSeleccionado.jpg";
const std::string Interface::pestaniaAmigosApagado                       = "PestaniaAmigosApagado.jpg";
const std::string Interface::pestaniaAmigosMensajesNuevos                = "PestaniaAmigosMensajesNuevos.jpg";
const std::string Interface::pestaniaAmigosRollover                      = "PestaniaAmigosRollover.jpg";
const std::string Interface::pestaniaAmigosSeleccionado                  = "PestaniaAmigosSeleccionado.jpg";
const std::string Interface::pestaniaGeneralApagado                      = "PestaniaGeneralApagado.jpg";
const std::string Interface::pestaniaGeneralMensajesNuevos               = "PestaniaGeneralMensajesNuevos.jpg";
const std::string Interface::pestaniaGeneralRollover                     = "PestaniaGeneralRollover.jpg";
const std::string Interface::pestaniaGeneralSeleccionado                 = "PestaniaGeneralSeleccionado.jpg";
const std::string Interface::pestaniaPersonalizadaApagado                = "PestaniaPersonalizadaApagado.jpg";
const std::string Interface::pestaniaPersonalizadaMensajesNuevos         = "PestaniaPersonalizadaMensajesNuevos.jpg";
const std::string Interface::pestaniaPersonalizadaRollover               = "PestaniaPersonalizadaRollover.jpg";
const std::string Interface::pestaniaPersonalizadaSeleccionado           = "PestaniaPersonalizadaSeleccionado.jpg";
const std::string Interface::plusDisabled                                = "PlusDisabled.bmp";
const std::string Interface::plusEnabled                                 = "PlusEnabled.bmp";
const std::string Interface::presentacion1                               = "Presentacion1.jpg";
const std::string Interface::presentacion2                               = "Presentacion2.jpg";
const std::string Interface::presentacion3                               = "Presentacion3.jpg";
const std::string Interface::presentacion4                               = "Presentacion4.jpg";
const std::string Interface::presentacion5                               = "Presentacion5.jpg";
const std::string Interface::presentacion6                               = "Presentacion6.jpg";
const std::string Interface::presentacion7                               = "Presentacion7.jpg";
const std::string Interface::presentacion8                               = "Presentacion8.jpg";
const std::string Interface::presentacion9                               = "Presentacion9.jpg";
const std::string Interface::progressBar                                 = "ProgressBar.png";
const std::string Interface::recuadroVentanaMascotas                     = "RecuadroVentanaMascotas.png";
const std::string Interface::recuadroVentanaMascotasClick                = "RecuadroVentanaMascotasClick.png";
const std::string Interface::recuadroVentanaMascotasDisabled             = "RecuadroVentanaMascotasDisabled.png";
const std::string Interface::recuadroVentanaMascotasRollover             = "RecuadroVentanaMascotasRollover.png";
const std::string Interface::regresarRollover                            = "RegresarRollover.gif";
const std::string Interface::ventanaAmigos                               = "VentanaAmigos.jpg";
const std::string Interface::ventanaAmigosAgregar                        = "VentanaAmigosAgregar.jpg";
const std::string Interface::ventanaAmigosCambiarPerfil                  = "VentanaAmigosCambiarPerfil.jpg";
const std::string Interface::ventanaAmigosSolicitudes                    = "VentanaAmigosSolicitudes.jpg";
const std::string Interface::ventanaBorrarChar                           = "VentanaBorrarChar.jpg";
const std::string Interface::ventanaBovedaCuentaCambiarContrasenia       = "VentanaBovedaCuentaCambiarContrasenia.jpg";
const std::string Interface::ventanaBovedaCuentaPass                     = "VentanaBovedaCuentaPass.jpg";
const std::string Interface::ventanaCambiarContrasenia                   = "VentanaCambiarContrasenia.jpg";
const std::string Interface::ventanaCantidad                             = "VentanaCantidad.jpg";
const std::string Interface::ventanaCargando                             = "VentanaCargando.jpg";
const std::string Interface::ventanaClanAdmin                            = "VentanaClanAdmin.jpg";
const std::string Interface::ventanaClanInfo                             = "VentanaClanInfo.jpg";
const std::string Interface::ventanaClanMemberInfo                       = "VentanaClanMemberInfo.jpg";
const std::string Interface::ventanaClanOfertaAlianza                    = "VentanaClanOfertaAlianza.jpg";
const std::string Interface::ventanaClanOfertaPaz                        = "VentanaClanOfertaPaz.jpg";
const std::string Interface::ventanaClanSolicitud                        = "VentanaClanSolicitud.jpg";
const std::string Interface::ventanaClanVerSolicitud                     = "VentanaClanVerSolicitud.jpg";
const std::string Interface::ventanaComercio                             = "VentanaComercio.jpg";
const std::string Interface::ventanaConectar                             = "VentanaConectar.jpg";
const std::string Interface::ventanaConfigurarConsola                    = "VentanaConfigurarConsola.jpg";
const std::string Interface::ventanaConfigurarTeclas                     = "VentanaConfigurarTeclas.jpg";
const std::string Interface::ventanaCrafteo                              = "VentanaCrafteo.jpg";
const std::string Interface::ventanaCrearCuenta                          = "VentanaCrearCuenta.jpg";
const std::string Interface::ventanaCrearPersonaje                       = "VentanaCrearPersonaje.jpg";
const std::string Interface::ventanaCuenta                               = "VentanaCuenta.jpg";
const std::string Interface::ventanaDialogos                             = "VentanaDialogos.jpg";
const std::string Interface::ventanaDuelo1v1                             = "VentanaDuelo1v1.jpg";
const std::string Interface::ventanaDuelo2v2                             = "VentanaDuelo2v2.jpg";
const std::string Interface::ventanaDuelo3v3                             = "VentanaDuelo3v3.jpg";
const std::string Interface::ventanaDuelo4v4                             = "VentanaDuelo4v4.jpg";
const std::string Interface::ventanaDuelos                               = "VentanaDuelos.jpg";
const std::string Interface::ventanaEditarCodex                          = "VentanaEditarCodex.jpg";
const std::string Interface::ventanaEditarWebsite                        = "VentanaEditarWebsite.jpg";
const std::string Interface::ventanaEsperandoDuelo                       = "VentanaEsperandoDuelo.jpg";
const std::string Interface::ventanaEstadisticaold_s                     = "VentanaEstadisticaold_s.jpg";
const std::string Interface::ventanaEstadisticas                         = "VentanaEstadisticas.jpg";
const std::string Interface::ventanaListaClanes                          = "VentanaListaClanes.jpg";
const std::string Interface::ventanaMapa                                 = "VentanaMapa.jpg";
const std::string Interface::ventanaMascotas                             = "VentanaMascotas.png";
const std::string Interface::ventanaMensajesPersonalizados               = "VentanaMensajesPersonalizados.jpg";
const std::string Interface::ventanaNoticiasClan                         = "VentanaNoticiasClan.jpg";
const std::string Interface::ventanaOpciones                             = "VentanaOpciones.jpg";
const std::string Interface::ventanaPrincipal                            = "VentanaPrincipal_.jpg";
const std::string Interface::ventanaResolucion                           = "VentanaResolucion.jpg";
const std::string Interface::ventanaSkills                               = "VentanaSkills.jpg";
const std::string Interface::ventanaTutorial                             = "VentanaTutorial.jpg";

// ---------------------------------------------------------
// convenience functions returing pointers to Sprite objects
// ---------------------------------------------------------
Sprite* Interface::createAmigosClickSprite()
{
    return Sprite::createWithSpriteFrameName(amigosClick);
}

Sprite* Interface::createAmigosMenueSprite()
{
    return Sprite::createWithSpriteFrameName(amigosMenue);
}

Sprite* Interface::createAmigosNuevoMensajeSprite()
{
    return Sprite::createWithSpriteFrameName(amigosNuevoMensaje);
}

Sprite* Interface::createAmigosRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(amigosRollover);
}

Sprite* Interface::createBOtonGrupoClickSprite()
{
    return Sprite::createWithSpriteFrameName(bOtonGrupoClick);
}

Sprite* Interface::createBotonAceptarCambioContraseniaSprite()
{
    return Sprite::createWithSpriteFrameName(botonAceptarCambioContrasenia);
}

Sprite* Interface::createBotonAceptarCambioContraseniaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonAceptarCambioContraseniaClick);
}

Sprite* Interface::createBotonAceptarCambioContraseniaDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonAceptarCambioContraseniaDisabled);
}

Sprite* Interface::createBotonAceptarCambioContraseniaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonAceptarCambioContraseniaRollover);
}

Sprite* Interface::createBotonAceptarSkillsSprite()
{
    return Sprite::createWithSpriteFrameName(botonAceptarSkills);
}

Sprite* Interface::createBotonAceptarSkillsClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonAceptarSkillsClick);
}

Sprite* Interface::createBotonAceptarSkillsDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonAceptarSkillsDisabled);
}

Sprite* Interface::createBotonAceptarSkillsRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonAceptarSkillsRollover);
}

Sprite* Interface::createBotonAmigosSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigos);
}

Sprite* Interface::createBotonAmigosAceptarSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosAceptar);
}

Sprite* Interface::createBotonAmigosAceptarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosAceptarClick);
}

Sprite* Interface::createBotonAmigosAceptarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosAceptarRollover);
}

Sprite* Interface::createBotonAmigosAceptarSolicitudSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosAceptarSolicitud);
}

Sprite* Interface::createBotonAmigosAceptarSolicitudClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosAceptarSolicitudClick);
}

Sprite* Interface::createBotonAmigosAceptarSolicitudRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosAceptarSolicitudRollover);
}

Sprite* Interface::createBotonAmigosAgregarSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosAgregar);
}

Sprite* Interface::createBotonAmigosAgregarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosAgregarClick);
}

Sprite* Interface::createBotonAmigosAgregarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosAgregarRollover);
}

Sprite* Interface::createBotonAmigosClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosClick);
}

Sprite* Interface::createBotonAmigosNombreSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosNombre);
}

Sprite* Interface::createBotonAmigosNombreClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosNombreClick);
}

Sprite* Interface::createBotonAmigosNombreRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosNombreRollover);
}

Sprite* Interface::createBotonAmigosRechazarSolicitudSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosRechazarSolicitud);
}

Sprite* Interface::createBotonAmigosRechazarSolicitudClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosRechazarSolicitudClick);
}

Sprite* Interface::createBotonAmigosRechazarSolicitudRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosRechazarSolicitudRollover);
}

Sprite* Interface::createBotonAmigosRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosRollover);
}

Sprite* Interface::createBotonAmigosSalasSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosSalas);
}

Sprite* Interface::createBotonAmigosSalasClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosSalasClick);
}

Sprite* Interface::createBotonAmigosSalasRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosSalasRollover);
}

Sprite* Interface::createBotonAmigosSolicitudesSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosSolicitudes);
}

Sprite* Interface::createBotonAmigosSolicitudesClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosSolicitudesClick);
}

Sprite* Interface::createBotonAmigosSolicitudesRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosSolicitudesRollover);
}

Sprite* Interface::createBotonAmigosTacSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosTac);
}

Sprite* Interface::createBotonAmigosTicSprite()
{
    return Sprite::createWithSpriteFrameName(botonAmigosTic);
}

Sprite* Interface::createBotonArmadurasSprite()
{
    return Sprite::createWithSpriteFrameName(botonArmaduras);
}

Sprite* Interface::createBotonArmadurasClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonArmadurasClick);
}

Sprite* Interface::createBotonArmadurasDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonArmadurasDisabled);
}

Sprite* Interface::createBotonArmadurasHoverSprite()
{
    return Sprite::createWithSpriteFrameName(botonArmadurasHover);
}

Sprite* Interface::createBotonArmasSprite()
{
    return Sprite::createWithSpriteFrameName(botonArmas);
}

Sprite* Interface::createBotonArmasClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonArmasClick);
}

Sprite* Interface::createBotonArmasDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonArmasDisabled);
}

Sprite* Interface::createBotonArmasHoverSprite()
{
    return Sprite::createWithSpriteFrameName(botonArmasHover);
}

Sprite* Interface::createBotonBorrarPersonajeSprite()
{
    return Sprite::createWithSpriteFrameName(botonBorrarPersonaje);
}

Sprite* Interface::createBotonBorrarPersonajeClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonBorrarPersonajeClick);
}

Sprite* Interface::createBotonBorrarPersonajeDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonBorrarPersonajeDisabled);
}

Sprite* Interface::createBotonBorrarPersonajeRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonBorrarPersonajeRollover);
}

Sprite* Interface::createBotonBovedaCuentaCambiarSprite()
{
    return Sprite::createWithSpriteFrameName(botonBovedaCuentaCambiar);
}

Sprite* Interface::createBotonBovedaCuentaCambiarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonBovedaCuentaCambiarClick);
}

Sprite* Interface::createBotonBovedaCuentaCambiarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonBovedaCuentaCambiarRollover);
}

Sprite* Interface::createBotonBovedaCuentaCambiar_ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonBovedaCuentaCambiar_Click);
}

Sprite* Interface::createBotonBovedaCuentaCambiar_HoverSprite()
{
    return Sprite::createWithSpriteFrameName(botonBovedaCuentaCambiar_Hover);
}

Sprite* Interface::createBotonBovedaCuentaIngresarSprite()
{
    return Sprite::createWithSpriteFrameName(botonBovedaCuentaIngresar);
}

Sprite* Interface::createBotonBovedaCuentaIngresarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonBovedaCuentaIngresarClick);
}

Sprite* Interface::createBotonBovedaCuentaIngresarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonBovedaCuentaIngresarRollover);
}

Sprite* Interface::createBotonBovedaCuentaIngresar_ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonBovedaCuentaIngresar_Click);
}

Sprite* Interface::createBotonBovedaCuentaIngresar_HoverSprite()
{
    return Sprite::createWithSpriteFrameName(botonBovedaCuentaIngresar_Hover);
}

Sprite* Interface::createBotonCambiarContraseniaSprite()
{
    return Sprite::createWithSpriteFrameName(botonCambiarContrasenia);
}

Sprite* Interface::createBotonCambiarContraseniaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonCambiarContraseniaClick);
}

Sprite* Interface::createBotonCambiarContraseniaDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonCambiarContraseniaDisabled);
}

Sprite* Interface::createBotonCambiarContraseniaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonCambiarContraseniaRollover);
}

Sprite* Interface::createBotonCancelarBloqueadoSprite()
{
    return Sprite::createWithSpriteFrameName(botonCancelarBloqueado);
}

Sprite* Interface::createBotonCerrarFormSprite()
{
    return Sprite::createWithSpriteFrameName(botonCerrarForm);
}

Sprite* Interface::createBotonCerrarFormClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonCerrarFormClick);
}

Sprite* Interface::createBotonCerrarFormDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonCerrarFormDisabled);
}

Sprite* Interface::createBotonCerrarFormRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonCerrarFormRollover);
}

Sprite* Interface::createBotonCheckSprite()
{
    return Sprite::createWithSpriteFrameName(botonCheck);
}

Sprite* Interface::createBotonCheckboxSprite()
{
    return Sprite::createWithSpriteFrameName(botonCheckbox);
}

Sprite* Interface::createBotonClanActualizarSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanActualizar);
}

Sprite* Interface::createBotonClanActualizarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanActualizarClick);
}

Sprite* Interface::createBotonClanActualizarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanActualizarDisabled);
}

Sprite* Interface::createBotonClanActualizarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanActualizarRollover);
}

Sprite* Interface::createBotonClanAlianzaSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanAlianza);
}

Sprite* Interface::createBotonClanAlianzaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanAlianzaClick);
}

Sprite* Interface::createBotonClanAlianzaDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanAlianzaDisabled);
}

Sprite* Interface::createBotonClanAlianzaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanAlianzaRollover);
}

Sprite* Interface::createBotonClanDetallesSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanDetalles);
}

Sprite* Interface::createBotonClanDetallesClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanDetallesClick);
}

Sprite* Interface::createBotonClanDetallesDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanDetallesDisabled);
}

Sprite* Interface::createBotonClanDetallesRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanDetallesRollover);
}

Sprite* Interface::createBotonClanEditarCodexSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarCodex);
}

Sprite* Interface::createBotonClanEditarCodexAceptarSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarCodexAceptar);
}

Sprite* Interface::createBotonClanEditarCodexAceptarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarCodexAceptarClick);
}

Sprite* Interface::createBotonClanEditarCodexAceptarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarCodexAceptarDisabled);
}

Sprite* Interface::createBotonClanEditarCodexAceptarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarCodexAceptarRollover);
}

Sprite* Interface::createBotonClanEditarCodexClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarCodexClick);
}

Sprite* Interface::createBotonClanEditarCodexDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarCodexDisabled);
}

Sprite* Interface::createBotonClanEditarCodexRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarCodexRollover);
}

Sprite* Interface::createBotonClanEditarUrlSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarUrl);
}

Sprite* Interface::createBotonClanEditarUrlClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarUrlClick);
}

Sprite* Interface::createBotonClanEditarUrlDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarUrlDisabled);
}

Sprite* Interface::createBotonClanEditarUrlRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarUrlRollover);
}

Sprite* Interface::createBotonClanEditarWebsiteAceptarSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarWebsiteAceptar);
}

Sprite* Interface::createBotonClanEditarWebsiteAceptarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarWebsiteAceptarClick);
}

Sprite* Interface::createBotonClanEditarWebsiteAceptarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarWebsiteAceptarDisabled);
}

Sprite* Interface::createBotonClanEditarWebsiteAceptarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEditarWebsiteAceptarRollover);
}

Sprite* Interface::createBotonClanEleccionesSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanElecciones);
}

Sprite* Interface::createBotonClanEleccionesClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEleccionesClick);
}

Sprite* Interface::createBotonClanEleccionesDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEleccionesDisabled);
}

Sprite* Interface::createBotonClanEleccionesRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanEleccionesRollover);
}

Sprite* Interface::createBotonClanInfoAlianzaSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoAlianza);
}

Sprite* Interface::createBotonClanInfoAlianzaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoAlianzaClick);
}

Sprite* Interface::createBotonClanInfoAlianzaDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoAlianzaDisabled);
}

Sprite* Interface::createBotonClanInfoAlianzaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoAlianzaRollover);
}

Sprite* Interface::createBotonClanInfoGuerraSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoGuerra);
}

Sprite* Interface::createBotonClanInfoGuerraClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoGuerraClick);
}

Sprite* Interface::createBotonClanInfoGuerraDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoGuerraDisabled);
}

Sprite* Interface::createBotonClanInfoGuerraRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoGuerraRollover);
}

Sprite* Interface::createBotonClanInfoPazSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoPaz);
}

Sprite* Interface::createBotonClanInfoPazClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoPazClick);
}

Sprite* Interface::createBotonClanInfoPazDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoPazDisabled);
}

Sprite* Interface::createBotonClanInfoPazRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoPazRollover);
}

Sprite* Interface::createBotonClanInfoSolicitarIngresoSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoSolicitarIngreso);
}

Sprite* Interface::createBotonClanInfoSolicitarIngresoClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoSolicitarIngresoClick);
}

Sprite* Interface::createBotonClanInfoSolicitarIngresoDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoSolicitarIngresoDisabled);
}

Sprite* Interface::createBotonClanInfoSolicitarIngresoRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanInfoSolicitarIngresoRollover);
}

Sprite* Interface::createBotonClanMemberInfoAceptarSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoAceptar);
}

Sprite* Interface::createBotonClanMemberInfoAceptarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoAceptarClick);
}

Sprite* Interface::createBotonClanMemberInfoAceptarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoAceptarDisabled);
}

Sprite* Interface::createBotonClanMemberInfoAceptarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoAceptarRollover);
}

Sprite* Interface::createBotonClanMemberInfoEcharSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoEchar);
}

Sprite* Interface::createBotonClanMemberInfoEcharClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoEcharClick);
}

Sprite* Interface::createBotonClanMemberInfoEcharDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoEcharDisabled);
}

Sprite* Interface::createBotonClanMemberInfoEcharRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoEcharRollover);
}

Sprite* Interface::createBotonClanMemberInfoPeticionSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoPeticion);
}

Sprite* Interface::createBotonClanMemberInfoPeticionClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoPeticionClick);
}

Sprite* Interface::createBotonClanMemberInfoPeticionDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoPeticionDisabled);
}

Sprite* Interface::createBotonClanMemberInfoPeticionRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoPeticionRollover);
}

Sprite* Interface::createBotonClanMemberInfoRechazarSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoRechazar);
}

Sprite* Interface::createBotonClanMemberInfoRechazarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoRechazarClick);
}

Sprite* Interface::createBotonClanMemberInfoRechazarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoRechazarDisabled);
}

Sprite* Interface::createBotonClanMemberInfoRechazarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanMemberInfoRechazarRollover);
}

Sprite* Interface::createBotonClanOfertaAceptarSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaAceptar);
}

Sprite* Interface::createBotonClanOfertaAceptarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaAceptarClick);
}

Sprite* Interface::createBotonClanOfertaAceptarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaAceptarDisabled);
}

Sprite* Interface::createBotonClanOfertaAceptarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaAceptarRollover);
}

Sprite* Interface::createBotonClanOfertaDetallesSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaDetalles);
}

Sprite* Interface::createBotonClanOfertaDetallesClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaDetallesClick);
}

Sprite* Interface::createBotonClanOfertaDetallesDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaDetallesDisabled);
}

Sprite* Interface::createBotonClanOfertaDetallesRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaDetallesRollover);
}

Sprite* Interface::createBotonClanOfertaRechazarSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaRechazar);
}

Sprite* Interface::createBotonClanOfertaRechazarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaRechazarClick);
}

Sprite* Interface::createBotonClanOfertaRechazarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaRechazarDisabled);
}

Sprite* Interface::createBotonClanOfertaRechazarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanOfertaRechazarRollover);
}

Sprite* Interface::createBotonClanPazSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanPaz);
}

Sprite* Interface::createBotonClanPazClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanPazClick);
}

Sprite* Interface::createBotonClanPazDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanPazDisabled);
}

Sprite* Interface::createBotonClanPazRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanPazRollover);
}

Sprite* Interface::createBotonClanSolicitudCerrarSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanSolicitudCerrar);
}

Sprite* Interface::createBotonClanSolicitudCerrarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanSolicitudCerrarClick);
}

Sprite* Interface::createBotonClanSolicitudCerrarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanSolicitudCerrarDisabled);
}

Sprite* Interface::createBotonClanSolicitudCerrarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanSolicitudCerrarRollover);
}

Sprite* Interface::createBotonClanSolicitudEnviarSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanSolicitudEnviar);
}

Sprite* Interface::createBotonClanSolicitudEnviarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanSolicitudEnviarClick);
}

Sprite* Interface::createBotonClanSolicitudEnviarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanSolicitudEnviarDisabled);
}

Sprite* Interface::createBotonClanSolicitudEnviarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanSolicitudEnviarRollover);
}

Sprite* Interface::createBotonClanVerSolicitudAceptarSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanVerSolicitudAceptar);
}

Sprite* Interface::createBotonClanVerSolicitudAceptarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanVerSolicitudAceptarClick);
}

Sprite* Interface::createBotonClanVerSolicitudAceptarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanVerSolicitudAceptarDisabled);
}

Sprite* Interface::createBotonClanVerSolicitudAceptarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanVerSolicitudAceptarRollover);
}

Sprite* Interface::createBotonClanesSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanes);
}

Sprite* Interface::createBotonClanesClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanesClick);
}

Sprite* Interface::createBotonClanesDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanesDisabled);
}

Sprite* Interface::createBotonClanesRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonClanesRollover);
}

Sprite* Interface::createBotonCodigoFuenteSprite()
{
    return Sprite::createWithSpriteFrameName(botonCodigoFuente);
}

Sprite* Interface::createBotonCodigoFuenteClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonCodigoFuenteClick);
}

Sprite* Interface::createBotonCodigoFuenteRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonCodigoFuenteRollover);
}

Sprite* Interface::createBotonComercioComprarSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioComprar);
}

Sprite* Interface::createBotonComercioComprarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioComprarClick);
}

Sprite* Interface::createBotonComercioComprarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioComprarDisabled);
}

Sprite* Interface::createBotonComercioComprarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioComprarRollover);
}

Sprite* Interface::createBotonComercioSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioSalir);
}

Sprite* Interface::createBotonComercioSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioSalirClick);
}

Sprite* Interface::createBotonComercioSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioSalirDisabled);
}

Sprite* Interface::createBotonComercioSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioSalirRollover);
}

Sprite* Interface::createBotonComercioVenderSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioVender);
}

Sprite* Interface::createBotonComercioVenderClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioVenderClick);
}

Sprite* Interface::createBotonComercioVenderDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioVenderDisabled);
}

Sprite* Interface::createBotonComercioVenderRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonComercioVenderRollover);
}

Sprite* Interface::createBotonConectarseSprite()
{
    return Sprite::createWithSpriteFrameName(botonConectarse);
}

Sprite* Interface::createBotonConectarseClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConectarseClick);
}

Sprite* Interface::createBotonConectarseDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConectarseDisabled);
}

Sprite* Interface::createBotonConectarseRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConectarseRollover);
}

Sprite* Interface::createBotonConfig1Sprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig1);
}

Sprite* Interface::createBotonConfig1ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig1Click);
}

Sprite* Interface::createBotonConfig1DisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig1Disabled);
}

Sprite* Interface::createBotonConfig1RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig1Rollover);
}

Sprite* Interface::createBotonConfig2Sprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig2);
}

Sprite* Interface::createBotonConfig2ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig2Click);
}

Sprite* Interface::createBotonConfig2DisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig2Disabled);
}

Sprite* Interface::createBotonConfig2RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig2Rollover);
}

Sprite* Interface::createBotonConfig3Sprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig3);
}

Sprite* Interface::createBotonConfig3ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig3Click);
}

Sprite* Interface::createBotonConfig3DisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig3Disabled);
}

Sprite* Interface::createBotonConfig3RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig3Rollover);
}

Sprite* Interface::createBotonConfig4Sprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig4);
}

Sprite* Interface::createBotonConfig4ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig4Click);
}

Sprite* Interface::createBotonConfig4DisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig4Disabled);
}

Sprite* Interface::createBotonConfig4RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig4Rollover);
}

Sprite* Interface::createBotonConfig5Sprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig5);
}

Sprite* Interface::createBotonConfig5ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig5Click);
}

Sprite* Interface::createBotonConfig5DisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig5Disabled);
}

Sprite* Interface::createBotonConfig5RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig5Rollover);
}

Sprite* Interface::createBotonConfig6Sprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig6);
}

Sprite* Interface::createBotonConfig6ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig6Click);
}

Sprite* Interface::createBotonConfig6DisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig6Disabled);
}

Sprite* Interface::createBotonConfig6RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig6Rollover);
}

Sprite* Interface::createBotonConfig7Sprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig7);
}

Sprite* Interface::createBotonConfig7ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig7Click);
}

Sprite* Interface::createBotonConfig7DisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig7Disabled);
}

Sprite* Interface::createBotonConfig7RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig7Rollover);
}

Sprite* Interface::createBotonConfig8Sprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig8);
}

Sprite* Interface::createBotonConfig8ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig8Click);
}

Sprite* Interface::createBotonConfig8DisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig8Disabled);
}

Sprite* Interface::createBotonConfig8RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig8Rollover);
}

Sprite* Interface::createBotonConfig9Sprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig9);
}

Sprite* Interface::createBotonConfig9ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig9Click);
}

Sprite* Interface::createBotonConfig9DisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig9Disabled);
}

Sprite* Interface::createBotonConfig9RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfig9Rollover);
}

Sprite* Interface::createBotonConfigCargarDefaultSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigCargarDefault);
}

Sprite* Interface::createBotonConfigCargarDefaultClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigCargarDefaultClick);
}

Sprite* Interface::createBotonConfigCargarDefaultRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigCargarDefaultRollover);
}

Sprite* Interface::createBotonConfigDefaultSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigDefault);
}

Sprite* Interface::createBotonConfigDefaultClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigDefaultClick);
}

Sprite* Interface::createBotonConfigDefaultDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigDefaultDisabled);
}

Sprite* Interface::createBotonConfigDefaultRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigDefaultRollover);
}

Sprite* Interface::createBotonConfigGuardarSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigGuardar);
}

Sprite* Interface::createBotonConfigGuardarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigGuardarClick);
}

Sprite* Interface::createBotonConfigGuardarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigGuardarRollover);
}

Sprite* Interface::createBotonConfigurarConsolaGuardarSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigurarConsolaGuardar);
}

Sprite* Interface::createBotonConfigurarConsolaGuardarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigurarConsolaGuardarClick);
}

Sprite* Interface::createBotonConfigurarConsolaGuardarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigurarConsolaGuardarDisabled);
}

Sprite* Interface::createBotonConfigurarConsolaGuardarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigurarConsolaGuardarRollover);
}

Sprite* Interface::createBotonConfigurarConsolaSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigurarConsolaSalir);
}

Sprite* Interface::createBotonConfigurarConsolaSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigurarConsolaSalirClick);
}

Sprite* Interface::createBotonConfigurarConsolaSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigurarConsolaSalirDisabled);
}

Sprite* Interface::createBotonConfigurarConsolaSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfigurarConsolaSalirRollover);
}

Sprite* Interface::createBotonConfirmarBloqueadoSprite()
{
    return Sprite::createWithSpriteFrameName(botonConfirmarBloqueado);
}

Sprite* Interface::createBotonConstruirSprite()
{
    return Sprite::createWithSpriteFrameName(botonConstruir);
}

Sprite* Interface::createBotonConstruirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonConstruirClick);
}

Sprite* Interface::createBotonConstruirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonConstruirDisabled);
}

Sprite* Interface::createBotonConstruirHoverSprite()
{
    return Sprite::createWithSpriteFrameName(botonConstruirHover);
}

Sprite* Interface::createBotonCrafteoSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrafteoSalir);
}

Sprite* Interface::createBotonCrafteoSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrafteoSalirClick);
}

Sprite* Interface::createBotonCrafteoSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrafteoSalirDisabled);
}

Sprite* Interface::createBotonCrafteoSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrafteoSalirRollover);
}

Sprite* Interface::createBotonCrearCuentaSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearCuenta);
}

Sprite* Interface::createBotonCrearCuentaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearCuentaClick);
}

Sprite* Interface::createBotonCrearCuentaDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearCuentaDisabled);
}

Sprite* Interface::createBotonCrearCuentaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearCuentaRollover);
}

Sprite* Interface::createBotonCrearPersonajeSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonaje);
}

Sprite* Interface::createBotonCrearPersonajeClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajeClick);
}

Sprite* Interface::createBotonCrearPersonajeDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajeDisabled);
}

Sprite* Interface::createBotonCrearPersonajeRegresarSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajeRegresar);
}

Sprite* Interface::createBotonCrearPersonajeRegresarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajeRegresarClick);
}

Sprite* Interface::createBotonCrearPersonajeRegresarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajeRegresarDisabled);
}

Sprite* Interface::createBotonCrearPersonajeRegresarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajeRegresarRollover);
}

Sprite* Interface::createBotonCrearPersonajeRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajeRollover);
}

Sprite* Interface::createBotonCrearPersonajesSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajes);
}

Sprite* Interface::createBotonCrearPersonajesClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajesClick);
}

Sprite* Interface::createBotonCrearPersonajesDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajesDisabled);
}

Sprite* Interface::createBotonCrearPersonajesRegresarSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajesRegresar);
}

Sprite* Interface::createBotonCrearPersonajesRegresarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajesRegresarClick);
}

Sprite* Interface::createBotonCrearPersonajesRegresarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajesRegresarDisabled);
}

Sprite* Interface::createBotonCrearPersonajesRegresarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajesRegresarRollover);
}

Sprite* Interface::createBotonCrearPersonajesRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonCrearPersonajesRollover);
}

Sprite* Interface::createBotonCruzSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonCruzSalir);
}

Sprite* Interface::createBotonCruzSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonCruzSalirClick);
}

Sprite* Interface::createBotonCruzSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonCruzSalirDisabled);
}

Sprite* Interface::createBotonCruzSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonCruzSalirRollover);
}

Sprite* Interface::createBotonDeleteCharCancelarSprite()
{
    return Sprite::createWithSpriteFrameName(botonDeleteCharCancelar);
}

Sprite* Interface::createBotonDeleteCharCancelarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDeleteCharCancelarClick);
}

Sprite* Interface::createBotonDeleteCharCancelarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonDeleteCharCancelarDisabled);
}

Sprite* Interface::createBotonDeleteCharCancelarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDeleteCharCancelarRollover);
}

Sprite* Interface::createBotonDeleteCharConfirmarSprite()
{
    return Sprite::createWithSpriteFrameName(botonDeleteCharConfirmar);
}

Sprite* Interface::createBotonDeleteCharConfirmarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDeleteCharConfirmarClick);
}

Sprite* Interface::createBotonDeleteCharConfirmarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonDeleteCharConfirmarDisabled);
}

Sprite* Interface::createBotonDeleteCharConfirmarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDeleteCharConfirmarRollover);
}

Sprite* Interface::createBotonDialogosAplicarSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosAplicar);
}

Sprite* Interface::createBotonDialogosAplicarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosAplicarClick);
}

Sprite* Interface::createBotonDialogosAplicarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosAplicarDisabled);
}

Sprite* Interface::createBotonDialogosAplicarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosAplicarRollover);
}

Sprite* Interface::createBotonDialogosDefectoSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosDefecto);
}

Sprite* Interface::createBotonDialogosDefectoClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosDefectoClick);
}

Sprite* Interface::createBotonDialogosDefectoDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosDefectoDisabled);
}

Sprite* Interface::createBotonDialogosDefectoRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosDefectoRollover);
}

Sprite* Interface::createBotonDialogosSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosSalir);
}

Sprite* Interface::createBotonDialogosSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosSalirClick);
}

Sprite* Interface::createBotonDialogosSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosSalirDisabled);
}

Sprite* Interface::createBotonDialogosSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosSalirRollover);
}

Sprite* Interface::createBotonDialogosTodoDefectoSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosTodoDefecto);
}

Sprite* Interface::createBotonDialogosTodoDefectoClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosTodoDefectoClick);
}

Sprite* Interface::createBotonDialogosTodoDefectoDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosTodoDefectoDisabled);
}

Sprite* Interface::createBotonDialogosTodoDefectoRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDialogosTodoDefectoRollover);
}

Sprite* Interface::createBotonDuelo1v1Sprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo1v1);
}

Sprite* Interface::createBotonDuelo1v1ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo1v1Click);
}

Sprite* Interface::createBotonDuelo1v1RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo1v1Rollover);
}

Sprite* Interface::createBotonDuelo2v2Sprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo2v2);
}

Sprite* Interface::createBotonDuelo2v2ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo2v2Click);
}

Sprite* Interface::createBotonDuelo2v2RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo2v2Rollover);
}

Sprite* Interface::createBotonDuelo3v3Sprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo3v3);
}

Sprite* Interface::createBotonDuelo3v3ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo3v3Click);
}

Sprite* Interface::createBotonDuelo3v3RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo3v3Rollover);
}

Sprite* Interface::createBotonDuelo4v4Sprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo4v4);
}

Sprite* Interface::createBotonDuelo4v4ClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo4v4Click);
}

Sprite* Interface::createBotonDuelo4v4RolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDuelo4v4Rollover);
}

Sprite* Interface::createBotonDueloAmigosTacSprite()
{
    return Sprite::createWithSpriteFrameName(botonDueloAmigosTac);
}

Sprite* Interface::createBotonDueloAmigosTicSprite()
{
    return Sprite::createWithSpriteFrameName(botonDueloAmigosTic);
}

Sprite* Interface::createBotonDueloCancelarEsperaSprite()
{
    return Sprite::createWithSpriteFrameName(botonDueloCancelarEspera);
}

Sprite* Interface::createBotonDueloCancelarEsperaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonDueloCancelarEsperaClick);
}

Sprite* Interface::createBotonDueloCancelarEsperaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonDueloCancelarEsperaRollover);
}

Sprite* Interface::createBotonEntrarPersonajeSprite()
{
    return Sprite::createWithSpriteFrameName(botonEntrarPersonaje);
}

Sprite* Interface::createBotonEntrarPersonajeClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonEntrarPersonajeClick);
}

Sprite* Interface::createBotonEntrarPersonajeDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonEntrarPersonajeDisabled);
}

Sprite* Interface::createBotonEntrarPersonajeRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonEntrarPersonajeRollover);
}

Sprite* Interface::createBotonEnviarDueloSprite()
{
    return Sprite::createWithSpriteFrameName(botonEnviarDuelo);
}

Sprite* Interface::createBotonEnviarDueloClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonEnviarDueloClick);
}

Sprite* Interface::createBotonEnviarDueloRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonEnviarDueloRollover);
}

Sprite* Interface::createBotonEstadisticasSprite()
{
    return Sprite::createWithSpriteFrameName(botonEstadisticas);
}

Sprite* Interface::createBotonEstadisticasClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonEstadisticasClick);
}

Sprite* Interface::createBotonEstadisticasDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonEstadisticasDisabled);
}

Sprite* Interface::createBotonEstadisticasRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonEstadisticasRollover);
}

Sprite* Interface::createBotonEstadisticasSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonEstadisticasSalir);
}

Sprite* Interface::createBotonEstadisticasSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonEstadisticasSalirClick);
}

Sprite* Interface::createBotonEstadisticasSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonEstadisticasSalirDisabled);
}

Sprite* Interface::createBotonEstadisticasSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonEstadisticasSalirRollover);
}

Sprite* Interface::createBotonFlechaDerechaSprite()
{
    return Sprite::createWithSpriteFrameName(botonFlechaDerecha);
}

Sprite* Interface::createBotonFlechaDerechaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonFlechaDerechaRollover);
}

Sprite* Interface::createBotonFlechaIzquierdaSprite()
{
    return Sprite::createWithSpriteFrameName(botonFlechaIzquierda);
}

Sprite* Interface::createBotonFlechaIzquierdaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonFlechaIzquierdaRollover);
}

Sprite* Interface::createBotonGrupoSprite()
{
    return Sprite::createWithSpriteFrameName(botonGrupo);
}

Sprite* Interface::createBotonGrupoDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonGrupoDisabled);
}

Sprite* Interface::createBotonGrupoNuevoMensajeSprite()
{
    return Sprite::createWithSpriteFrameName(botonGrupoNuevoMensaje);
}

Sprite* Interface::createBotonGrupoRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonGrupoRollover);
}

Sprite* Interface::createBotonItemsSprite()
{
    return Sprite::createWithSpriteFrameName(botonItems);
}

Sprite* Interface::createBotonItemsClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonItemsClick);
}

Sprite* Interface::createBotonItemsDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonItemsDisabled);
}

Sprite* Interface::createBotonItemsHoverSprite()
{
    return Sprite::createWithSpriteFrameName(botonItemsHover);
}

Sprite* Interface::createBotonLiberarMascotasSprite()
{
    return Sprite::createWithSpriteFrameName(botonLiberarMascotas);
}

Sprite* Interface::createBotonLiberarMascotasClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonLiberarMascotasClick);
}

Sprite* Interface::createBotonLiberarMascotasDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonLiberarMascotasDisabled);
}

Sprite* Interface::createBotonLiberarMascotasRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonLiberarMascotasRollover);
}

Sprite* Interface::createBotonListaClanesDetalleSprite()
{
    return Sprite::createWithSpriteFrameName(botonListaClanesDetalle);
}

Sprite* Interface::createBotonListaClanesDetalleClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonListaClanesDetalleClick);
}

Sprite* Interface::createBotonListaClanesDetalleRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonListaClanesDetalleRollover);
}

Sprite* Interface::createBotonManualSprite()
{
    return Sprite::createWithSpriteFrameName(botonManual);
}

Sprite* Interface::createBotonManualClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonManualClick);
}

Sprite* Interface::createBotonManualRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonManualRollover);
}

Sprite* Interface::createBotonMapaSprite()
{
    return Sprite::createWithSpriteFrameName(botonMapa);
}

Sprite* Interface::createBotonMapaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMapaClick);
}

Sprite* Interface::createBotonMapaDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonMapaDisabled);
}

Sprite* Interface::createBotonMapaDungeonsSprite()
{
    return Sprite::createWithSpriteFrameName(botonMapaDungeons);
}

Sprite* Interface::createBotonMapaDungeonsClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMapaDungeonsClick);
}

Sprite* Interface::createBotonMapaDungeonsRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMapaDungeonsRollover);
}

Sprite* Interface::createBotonMapaMundoSprite()
{
    return Sprite::createWithSpriteFrameName(botonMapaMundo);
}

Sprite* Interface::createBotonMapaMundoClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMapaMundoClick);
}

Sprite* Interface::createBotonMapaMundoRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMapaMundoRollover);
}

Sprite* Interface::createBotonMapaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMapaRollover);
}

Sprite* Interface::createBotonMasSkillsSprite()
{
    return Sprite::createWithSpriteFrameName(botonMasSkills);
}

Sprite* Interface::createBotonMasSkillsClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMasSkillsClick);
}

Sprite* Interface::createBotonMasSkillsDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonMasSkillsDisabled);
}

Sprite* Interface::createBotonMasSkillsRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMasSkillsRollover);
}

Sprite* Interface::createBotonMascotaSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotaSalir);
}

Sprite* Interface::createBotonMascotaSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotaSalirClick);
}

Sprite* Interface::createBotonMascotaSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotaSalirDisabled);
}

Sprite* Interface::createBotonMascotaSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotaSalirRollover);
}

Sprite* Interface::createBotonMascotasLiberarSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotasLiberar);
}

Sprite* Interface::createBotonMascotasLiberarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotasLiberarClick);
}

Sprite* Interface::createBotonMascotasLiberarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotasLiberarDisabled);
}

Sprite* Interface::createBotonMascotasLiberarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotasLiberarRollover);
}

Sprite* Interface::createBotonMascotasSeleccionarSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotasSeleccionar);
}

Sprite* Interface::createBotonMascotasSeleccionarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotasSeleccionarClick);
}

Sprite* Interface::createBotonMascotasSeleccionarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotasSeleccionarDisabled);
}

Sprite* Interface::createBotonMascotasSeleccionarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMascotasSeleccionarRollover);
}

Sprite* Interface::createBotonMejorarSprite()
{
    return Sprite::createWithSpriteFrameName(botonMejorar);
}

Sprite* Interface::createBotonMejorarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMejorarClick);
}

Sprite* Interface::createBotonMejorarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonMejorarDisabled);
}

Sprite* Interface::createBotonMejorarHoverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMejorarHover);
}

Sprite* Interface::createBotonMenosSkillsSprite()
{
    return Sprite::createWithSpriteFrameName(botonMenosSkills);
}

Sprite* Interface::createBotonMenosSkillsClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMenosSkillsClick);
}

Sprite* Interface::createBotonMenosSkillsDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonMenosSkillsDisabled);
}

Sprite* Interface::createBotonMenosSkillsRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMenosSkillsRollover);
}

Sprite* Interface::createBotonMensajesGuardarSprite()
{
    return Sprite::createWithSpriteFrameName(botonMensajesGuardar);
}

Sprite* Interface::createBotonMensajesGuardarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMensajesGuardarClick);
}

Sprite* Interface::createBotonMensajesGuardarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonMensajesGuardarDisabled);
}

Sprite* Interface::createBotonMensajesGuardarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMensajesGuardarRollover);
}

Sprite* Interface::createBotonMensajesSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonMensajesSalir);
}

Sprite* Interface::createBotonMensajesSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMensajesSalirClick);
}

Sprite* Interface::createBotonMensajesSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonMensajesSalirDisabled);
}

Sprite* Interface::createBotonMensajesSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMensajesSalirRollover);
}

Sprite* Interface::createBotonMoverHechiAbajoSprite()
{
    return Sprite::createWithSpriteFrameName(botonMoverHechiAbajo);
}

Sprite* Interface::createBotonMoverHechiAbajoClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMoverHechiAbajoClick);
}

Sprite* Interface::createBotonMoverHechiAbajoRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMoverHechiAbajoRollover);
}

Sprite* Interface::createBotonMoverHechiArribaSprite()
{
    return Sprite::createWithSpriteFrameName(botonMoverHechiArriba);
}

Sprite* Interface::createBotonMoverHechiArribaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonMoverHechiArribaClick);
}

Sprite* Interface::createBotonMoverHechiArribaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonMoverHechiArribaRollover);
}

Sprite* Interface::createBotonNoticiasClanAceptarSprite()
{
    return Sprite::createWithSpriteFrameName(botonNoticiasClanAceptar);
}

Sprite* Interface::createBotonNoticiasClanAceptarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonNoticiasClanAceptarClick);
}

Sprite* Interface::createBotonNoticiasClanAceptarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonNoticiasClanAceptarDisabled);
}

Sprite* Interface::createBotonNoticiasClanAceptarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonNoticiasClanAceptarRollover);
}

Sprite* Interface::createBotonOpcionesSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpciones);
}

Sprite* Interface::createBotonOpcionesCambiarContraseniaSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesCambiarContrasenia);
}

Sprite* Interface::createBotonOpcionesCambiarContraseniaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesCambiarContraseniaClick);
}

Sprite* Interface::createBotonOpcionesCambiarContraseniaDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesCambiarContraseniaDisabled);
}

Sprite* Interface::createBotonOpcionesCambiarContraseniaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesCambiarContraseniaRollover);
}

Sprite* Interface::createBotonOpcionesClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesClick);
}

Sprite* Interface::createBotonOpcionesConfigurarTeclasSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesConfigurarTeclas);
}

Sprite* Interface::createBotonOpcionesConfigurarTeclasClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesConfigurarTeclasClick);
}

Sprite* Interface::createBotonOpcionesConfigurarTeclasDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesConfigurarTeclasDisabled);
}

Sprite* Interface::createBotonOpcionesConfigurarTeclasRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesConfigurarTeclasRollover);
}

Sprite* Interface::createBotonOpcionesDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesDisabled);
}

Sprite* Interface::createBotonOpcionesManualSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesManual);
}

Sprite* Interface::createBotonOpcionesManualClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesManualClick);
}

Sprite* Interface::createBotonOpcionesManualDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesManualDisabled);
}

Sprite* Interface::createBotonOpcionesManualRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesManualRollover);
}

Sprite* Interface::createBotonOpcionesMapaSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesMapa);
}

Sprite* Interface::createBotonOpcionesMapaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesMapaClick);
}

Sprite* Interface::createBotonOpcionesMapaDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesMapaDisabled);
}

Sprite* Interface::createBotonOpcionesMapaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesMapaRollover);
}

Sprite* Interface::createBotonOpcionesMensajesPersonalizadosSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesMensajesPersonalizados);
}

Sprite* Interface::createBotonOpcionesMensajesPersonalizadosClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesMensajesPersonalizadosClick);
}

Sprite* Interface::createBotonOpcionesMensajesPersonalizadosDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesMensajesPersonalizadosDisabled);
}

Sprite* Interface::createBotonOpcionesMensajesPersonalizadosRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesMensajesPersonalizadosRollover);
}

Sprite* Interface::createBotonOpcionesRadioSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesRadio);
}

Sprite* Interface::createBotonOpcionesRadioClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesRadioClick);
}

Sprite* Interface::createBotonOpcionesRadioDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesRadioDisabled);
}

Sprite* Interface::createBotonOpcionesRadioRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesRadioRollover);
}

Sprite* Interface::createBotonOpcionesRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesRollover);
}

Sprite* Interface::createBotonOpcionesSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesSalir);
}

Sprite* Interface::createBotonOpcionesSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesSalirClick);
}

Sprite* Interface::createBotonOpcionesSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesSalirDisabled);
}

Sprite* Interface::createBotonOpcionesSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesSalirRollover);
}

Sprite* Interface::createBotonOpcionesSoporteSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesSoporte);
}

Sprite* Interface::createBotonOpcionesSoporteClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesSoporteClick);
}

Sprite* Interface::createBotonOpcionesSoporteDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesSoporteDisabled);
}

Sprite* Interface::createBotonOpcionesSoporteRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesSoporteRollover);
}

Sprite* Interface::createBotonOpcionesTutorialSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesTutorial);
}

Sprite* Interface::createBotonOpcionesTutorialClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesTutorialClick);
}

Sprite* Interface::createBotonOpcionesTutorialDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesTutorialDisabled);
}

Sprite* Interface::createBotonOpcionesTutorialRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonOpcionesTutorialRollover);
}

Sprite* Interface::createBotonRecuperarCuentaSprite()
{
    return Sprite::createWithSpriteFrameName(botonRecuperarCuenta);
}

Sprite* Interface::createBotonRecuperarCuentaClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonRecuperarCuentaClick);
}

Sprite* Interface::createBotonRecuperarCuentaDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonRecuperarCuentaDisabled);
}

Sprite* Interface::createBotonRecuperarCuentaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonRecuperarCuentaRollover);
}

Sprite* Interface::createBotonReglamentoSprite()
{
    return Sprite::createWithSpriteFrameName(botonReglamento);
}

Sprite* Interface::createBotonReglamentoClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonReglamentoClick);
}

Sprite* Interface::createBotonReglamentoRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonReglamentoRollover);
}

Sprite* Interface::createBotonResolucionNoSprite()
{
    return Sprite::createWithSpriteFrameName(botonResolucionNo);
}

Sprite* Interface::createBotonResolucionNoClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonResolucionNoClick);
}

Sprite* Interface::createBotonResolucionNoDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonResolucionNoDisabled);
}

Sprite* Interface::createBotonResolucionNoRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonResolucionNoRollover);
}

Sprite* Interface::createBotonResolucionSiSprite()
{
    return Sprite::createWithSpriteFrameName(botonResolucionSi);
}

Sprite* Interface::createBotonResolucionSiClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonResolucionSiClick);
}

Sprite* Interface::createBotonResolucionSiDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonResolucionSiDisabled);
}

Sprite* Interface::createBotonResolucionSiRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonResolucionSiRollover);
}

Sprite* Interface::createBotonSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalir);
}

Sprite* Interface::createBotonSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirClick);
}

Sprite* Interface::createBotonSalirClickConnectSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirClickConnect);
}

Sprite* Interface::createBotonSalirConnectSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirConnect);
}

Sprite* Interface::createBotonSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirDisabled);
}

Sprite* Interface::createBotonSalirMascotasSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirMascotas);
}

Sprite* Interface::createBotonSalirMascotasClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirMascotasClick);
}

Sprite* Interface::createBotonSalirMascotasDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirMascotasDisabled);
}

Sprite* Interface::createBotonSalirMascotasRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirMascotasRollover);
}

Sprite* Interface::createBotonSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirRollover);
}

Sprite* Interface::createBotonSalirSkillsSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirSkills);
}

Sprite* Interface::createBotonSalirSkillsClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirSkillsClick);
}

Sprite* Interface::createBotonSalirSkillsDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirSkillsDisabled);
}

Sprite* Interface::createBotonSalirSkillsRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonSalirSkillsRollover);
}

Sprite* Interface::createBotonSeleccionarMascotasSprite()
{
    return Sprite::createWithSpriteFrameName(botonSeleccionarMascotas);
}

Sprite* Interface::createBotonSeleccionarMascotasClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonSeleccionarMascotasClick);
}

Sprite* Interface::createBotonSeleccionarMascotasDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonSeleccionarMascotasDisabled);
}

Sprite* Interface::createBotonSeleccionarMascotasRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonSeleccionarMascotasRollover);
}

Sprite* Interface::createBotonSkillSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkill);
}

Sprite* Interface::createBotonSkillClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillClick);
}

Sprite* Interface::createBotonSkillDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillDisabled);
}

Sprite* Interface::createBotonSkillRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillRollover);
}

Sprite* Interface::createBotonSkillsAceptarSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsAceptar);
}

Sprite* Interface::createBotonSkillsAceptarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsAceptarClick);
}

Sprite* Interface::createBotonSkillsAceptarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsAceptarDisabled);
}

Sprite* Interface::createBotonSkillsAceptarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsAceptarRollover);
}

Sprite* Interface::createBotonSkillsMasSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsMas);
}

Sprite* Interface::createBotonSkillsMasClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsMasClick);
}

Sprite* Interface::createBotonSkillsMasDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsMasDisabled);
}

Sprite* Interface::createBotonSkillsMasRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsMasRollover);
}

Sprite* Interface::createBotonSkillsMenosSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsMenos);
}

Sprite* Interface::createBotonSkillsMenosClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsMenosClick);
}

Sprite* Interface::createBotonSkillsMenosDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsMenosDisabled);
}

Sprite* Interface::createBotonSkillsMenosRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsMenosRollover);
}

Sprite* Interface::createBotonSkillsSalirSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsSalir);
}

Sprite* Interface::createBotonSkillsSalirClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsSalirClick);
}

Sprite* Interface::createBotonSkillsSalirDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsSalirDisabled);
}

Sprite* Interface::createBotonSkillsSalirRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonSkillsSalirRollover);
}

Sprite* Interface::createBotonTirarSprite()
{
    return Sprite::createWithSpriteFrameName(botonTirar);
}

Sprite* Interface::createBotonTirarClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonTirarClick);
}

Sprite* Interface::createBotonTirarDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonTirarDisabled);
}

Sprite* Interface::createBotonTirarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonTirarRollover);
}

Sprite* Interface::createBotonTirarTodoSprite()
{
    return Sprite::createWithSpriteFrameName(botonTirarTodo);
}

Sprite* Interface::createBotonTirarTodoClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonTirarTodoClick);
}

Sprite* Interface::createBotonTirarTodoDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonTirarTodoDisabled);
}

Sprite* Interface::createBotonTirarTodoRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonTirarTodoRollover);
}

Sprite* Interface::createBotonTutorialAnteriorSprite()
{
    return Sprite::createWithSpriteFrameName(botonTutorialAnterior);
}

Sprite* Interface::createBotonTutorialAnteriorClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonTutorialAnteriorClick);
}

Sprite* Interface::createBotonTutorialAnteriorDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonTutorialAnteriorDisabled);
}

Sprite* Interface::createBotonTutorialAnteriorRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonTutorialAnteriorRollover);
}

Sprite* Interface::createBotonTutorialSiguienteSprite()
{
    return Sprite::createWithSpriteFrameName(botonTutorialSiguiente);
}

Sprite* Interface::createBotonTutorialSiguienteClickSprite()
{
    return Sprite::createWithSpriteFrameName(botonTutorialSiguienteClick);
}

Sprite* Interface::createBotonTutorialSiguienteDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(botonTutorialSiguienteDisabled);
}

Sprite* Interface::createBotonTutorialSiguienteRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(botonTutorialSiguienteRollover);
}

Sprite* Interface::createCajaMascotaSprite()
{
    return Sprite::createWithSpriteFrameName(cajaMascota);
}

Sprite* Interface::createCajaMascotaClickSprite()
{
    return Sprite::createWithSpriteFrameName(cajaMascotaClick);
}

Sprite* Interface::createCajaMascotaDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(cajaMascotaDisabled);
}

Sprite* Interface::createCajaMascotaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(cajaMascotaRollover);
}

Sprite* Interface::createCentroHechizosSprite()
{
    return Sprite::createWithSpriteFrameName(centroHechizos);
}

Sprite* Interface::createCentroInventarioSprite()
{
    return Sprite::createWithSpriteFrameName(centroInventario);
}

Sprite* Interface::createEstrellaBrillanteSprite()
{
    return Sprite::createWithSpriteFrameName(estrellaBrillante);
}

Sprite* Interface::createEstrellaMitadSprite()
{
    return Sprite::createWithSpriteFrameName(estrellaMitad);
}

Sprite* Interface::createEstrellaSimpleSprite()
{
    return Sprite::createWithSpriteFrameName(estrellaSimple);
}

Sprite* Interface::createIconConfigDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(iconConfigDisabled);
}

Sprite* Interface::createIconConfigEnabledSprite()
{
    return Sprite::createWithSpriteFrameName(iconConfigEnabled);
}

Sprite* Interface::createMarcoAmigoOfflineSprite()
{
    return Sprite::createWithSpriteFrameName(marcoAmigoOffline);
}

Sprite* Interface::createMarcoAmigoOnlineSprite()
{
    return Sprite::createWithSpriteFrameName(marcoAmigoOnline);
}

Sprite* Interface::createMarcoAmigoSalaSprite()
{
    return Sprite::createWithSpriteFrameName(marcoAmigoSala);
}

Sprite* Interface::createMarcoAmigoSalaNuevoMensajeSprite()
{
    return Sprite::createWithSpriteFrameName(marcoAmigoSalaNuevoMensaje);
}

Sprite* Interface::createMarcoAmigoSalaSeleccionadaSprite()
{
    return Sprite::createWithSpriteFrameName(marcoAmigoSalaSeleccionada);
}

Sprite* Interface::createMarcoItemsCrafteoSprite()
{
    return Sprite::createWithSpriteFrameName(marcoItemsCrafteo);
}

Sprite* Interface::createMinusDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(minusDisabled);
}

Sprite* Interface::createMinusEnabledSprite()
{
    return Sprite::createWithSpriteFrameName(minusEnabled);
}

Sprite* Interface::createNoMostrarTutorialSprite()
{
    return Sprite::createWithSpriteFrameName(noMostrarTutorial);
}

Sprite* Interface::createOriginArghalSprite()
{
    return Sprite::createWithSpriteFrameName(originArghal);
}

Sprite* Interface::createOriginBanderbillSprite()
{
    return Sprite::createWithSpriteFrameName(originBanderbill);
}

Sprite* Interface::createOriginLindosSprite()
{
    return Sprite::createWithSpriteFrameName(originLindos);
}

Sprite* Interface::createOriginNixSprite()
{
    return Sprite::createWithSpriteFrameName(originNix);
}

Sprite* Interface::createOriginUllathorpeSprite()
{
    return Sprite::createWithSpriteFrameName(originUllathorpe);
}

Sprite* Interface::createPartyClickSprite()
{
    return Sprite::createWithSpriteFrameName(partyClick);
}

Sprite* Interface::createPartyMenueSprite()
{
    return Sprite::createWithSpriteFrameName(partyMenue);
}

Sprite* Interface::createPartyRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(partyRollover);
}

Sprite* Interface::createPestaniaAccionesApagadoSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAccionesApagado);
}

Sprite* Interface::createPestaniaAccionesMensajesNuevosSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAccionesMensajesNuevos);
}

Sprite* Interface::createPestaniaAccionesRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAccionesRollover);
}

Sprite* Interface::createPestaniaAccionesSeleccionadoSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAccionesSeleccionado);
}

Sprite* Interface::createPestaniaAgrupacionesApagadoSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAgrupacionesApagado);
}

Sprite* Interface::createPestaniaAgrupacionesMensajesNuevosSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAgrupacionesMensajesNuevos);
}

Sprite* Interface::createPestaniaAgrupacionesRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAgrupacionesRollover);
}

Sprite* Interface::createPestaniaAgrupacionesSeleccionadoSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAgrupacionesSeleccionado);
}

Sprite* Interface::createPestaniaAmigosApagadoSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAmigosApagado);
}

Sprite* Interface::createPestaniaAmigosMensajesNuevosSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAmigosMensajesNuevos);
}

Sprite* Interface::createPestaniaAmigosRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAmigosRollover);
}

Sprite* Interface::createPestaniaAmigosSeleccionadoSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaAmigosSeleccionado);
}

Sprite* Interface::createPestaniaGeneralApagadoSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaGeneralApagado);
}

Sprite* Interface::createPestaniaGeneralMensajesNuevosSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaGeneralMensajesNuevos);
}

Sprite* Interface::createPestaniaGeneralRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaGeneralRollover);
}

Sprite* Interface::createPestaniaGeneralSeleccionadoSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaGeneralSeleccionado);
}

Sprite* Interface::createPestaniaPersonalizadaApagadoSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaPersonalizadaApagado);
}

Sprite* Interface::createPestaniaPersonalizadaMensajesNuevosSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaPersonalizadaMensajesNuevos);
}

Sprite* Interface::createPestaniaPersonalizadaRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaPersonalizadaRollover);
}

Sprite* Interface::createPestaniaPersonalizadaSeleccionadoSprite()
{
    return Sprite::createWithSpriteFrameName(pestaniaPersonalizadaSeleccionado);
}

Sprite* Interface::createPlusDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(plusDisabled);
}

Sprite* Interface::createPlusEnabledSprite()
{
    return Sprite::createWithSpriteFrameName(plusEnabled);
}

Sprite* Interface::createPresentacion1Sprite()
{
    return Sprite::createWithSpriteFrameName(presentacion1);
}

Sprite* Interface::createPresentacion2Sprite()
{
    return Sprite::createWithSpriteFrameName(presentacion2);
}

Sprite* Interface::createPresentacion3Sprite()
{
    return Sprite::createWithSpriteFrameName(presentacion3);
}

Sprite* Interface::createPresentacion4Sprite()
{
    return Sprite::createWithSpriteFrameName(presentacion4);
}

Sprite* Interface::createPresentacion5Sprite()
{
    return Sprite::createWithSpriteFrameName(presentacion5);
}

Sprite* Interface::createPresentacion6Sprite()
{
    return Sprite::createWithSpriteFrameName(presentacion6);
}

Sprite* Interface::createPresentacion7Sprite()
{
    return Sprite::createWithSpriteFrameName(presentacion7);
}

Sprite* Interface::createPresentacion8Sprite()
{
    return Sprite::createWithSpriteFrameName(presentacion8);
}

Sprite* Interface::createPresentacion9Sprite()
{
    return Sprite::createWithSpriteFrameName(presentacion9);
}

Sprite* Interface::createProgressBarSprite()
{
    return Sprite::createWithSpriteFrameName(progressBar);
}

Sprite* Interface::createRecuadroVentanaMascotasSprite()
{
    return Sprite::createWithSpriteFrameName(recuadroVentanaMascotas);
}

Sprite* Interface::createRecuadroVentanaMascotasClickSprite()
{
    return Sprite::createWithSpriteFrameName(recuadroVentanaMascotasClick);
}

Sprite* Interface::createRecuadroVentanaMascotasDisabledSprite()
{
    return Sprite::createWithSpriteFrameName(recuadroVentanaMascotasDisabled);
}

Sprite* Interface::createRecuadroVentanaMascotasRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(recuadroVentanaMascotasRollover);
}

Sprite* Interface::createRegresarRolloverSprite()
{
    return Sprite::createWithSpriteFrameName(regresarRollover);
}

Sprite* Interface::createVentanaAmigosSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaAmigos);
}

Sprite* Interface::createVentanaAmigosAgregarSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaAmigosAgregar);
}

Sprite* Interface::createVentanaAmigosCambiarPerfilSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaAmigosCambiarPerfil);
}

Sprite* Interface::createVentanaAmigosSolicitudesSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaAmigosSolicitudes);
}

Sprite* Interface::createVentanaBorrarCharSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaBorrarChar);
}

Sprite* Interface::createVentanaBovedaCuentaCambiarContraseniaSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaBovedaCuentaCambiarContrasenia);
}

Sprite* Interface::createVentanaBovedaCuentaPassSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaBovedaCuentaPass);
}

Sprite* Interface::createVentanaCambiarContraseniaSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaCambiarContrasenia);
}

Sprite* Interface::createVentanaCantidadSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaCantidad);
}

Sprite* Interface::createVentanaCargandoSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaCargando);
}

Sprite* Interface::createVentanaClanAdminSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaClanAdmin);
}

Sprite* Interface::createVentanaClanInfoSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaClanInfo);
}

Sprite* Interface::createVentanaClanMemberInfoSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaClanMemberInfo);
}

Sprite* Interface::createVentanaClanOfertaAlianzaSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaClanOfertaAlianza);
}

Sprite* Interface::createVentanaClanOfertaPazSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaClanOfertaPaz);
}

Sprite* Interface::createVentanaClanSolicitudSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaClanSolicitud);
}

Sprite* Interface::createVentanaClanVerSolicitudSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaClanVerSolicitud);
}

Sprite* Interface::createVentanaComercioSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaComercio);
}

Sprite* Interface::createVentanaConectarSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaConectar);
}

Sprite* Interface::createVentanaConfigurarConsolaSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaConfigurarConsola);
}

Sprite* Interface::createVentanaConfigurarTeclasSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaConfigurarTeclas);
}

Sprite* Interface::createVentanaCrafteoSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaCrafteo);
}

Sprite* Interface::createVentanaCrearCuentaSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaCrearCuenta);
}

Sprite* Interface::createVentanaCrearPersonajeSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaCrearPersonaje);
}

Sprite* Interface::createVentanaCuentaSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaCuenta);
}

Sprite* Interface::createVentanaDialogosSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaDialogos);
}

Sprite* Interface::createVentanaDuelo1v1Sprite()
{
    return Sprite::createWithSpriteFrameName(ventanaDuelo1v1);
}

Sprite* Interface::createVentanaDuelo2v2Sprite()
{
    return Sprite::createWithSpriteFrameName(ventanaDuelo2v2);
}

Sprite* Interface::createVentanaDuelo3v3Sprite()
{
    return Sprite::createWithSpriteFrameName(ventanaDuelo3v3);
}

Sprite* Interface::createVentanaDuelo4v4Sprite()
{
    return Sprite::createWithSpriteFrameName(ventanaDuelo4v4);
}

Sprite* Interface::createVentanaDuelosSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaDuelos);
}

Sprite* Interface::createVentanaEditarCodexSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaEditarCodex);
}

Sprite* Interface::createVentanaEditarWebsiteSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaEditarWebsite);
}

Sprite* Interface::createVentanaEsperandoDueloSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaEsperandoDuelo);
}

Sprite* Interface::createVentanaEstadisticaold_sSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaEstadisticaold_s);
}

Sprite* Interface::createVentanaEstadisticasSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaEstadisticas);
}

Sprite* Interface::createVentanaListaClanesSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaListaClanes);
}

Sprite* Interface::createVentanaMapaSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaMapa);
}

Sprite* Interface::createVentanaMascotasSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaMascotas);
}

Sprite* Interface::createVentanaMensajesPersonalizadosSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaMensajesPersonalizados);
}

Sprite* Interface::createVentanaNoticiasClanSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaNoticiasClan);
}

Sprite* Interface::createVentanaOpcionesSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaOpciones);
}

Sprite* Interface::createVentanaPrincipalSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaPrincipal);
}

Sprite* Interface::createVentanaResolucionSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaResolucion);
}

Sprite* Interface::createVentanaSkillsSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaSkills);
}

Sprite* Interface::createVentanaTutorialSprite()
{
    return Sprite::createWithSpriteFrameName(ventanaTutorial);
}

// ------------------------------------------------
// convenience functions returning animation frames
// ------------------------------------------------

Vector<SpriteFrame*> Interface::getPRESENTACIONAnimationFrames()
{
	SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> frames;
	frames.reserve(5);
	frames.pushBack(frameCache->getSpriteFrameByName(presentacion1));
	frames.pushBack(frameCache->getSpriteFrameByName(presentacion2));
	frames.pushBack(frameCache->getSpriteFrameByName(presentacion3));
	frames.pushBack(frameCache->getSpriteFrameByName(presentacion4));
	frames.pushBack(frameCache->getSpriteFrameByName(presentacion5));
	frames.pushBack(frameCache->getSpriteFrameByName(presentacion6));
	frames.pushBack(frameCache->getSpriteFrameByName(presentacion7));
	frames.pushBack(frameCache->getSpriteFrameByName(presentacion8));
	frames.pushBack(frameCache->getSpriteFrameByName(presentacion9));
	return frames;
}

// ----------
// animations
// --

Animate* Interface::createPRESENTACIONAnimateAction(float delay, unsigned int loops)
{
	return Animate::create(Animation::createWithSpriteFrames(getPRESENTACIONAnimationFrames(), delay, loops));
}

}; // namespace

