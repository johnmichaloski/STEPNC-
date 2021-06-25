//
//
//
#pragma once

#include "ExpressUtils.h"
#include "stepnc_schemaSchemaDeclarations.h"

namespace Express{
extern CStringVector GetAllstepnc_schemaEntities();
class Eapproval :
		public IStepNode
{
public:
	CLASSDEF(Eapproval); 
	Eapproval_statusPtr status; 
	ElabelPtr level; 
};
class Eapproval_status :
		public IStepNode
{
public:
	CLASSDEF(Eapproval_status); 
	ElabelPtr name; 
};
class Edate_and_time :
		public IStepNode
{
public:
	CLASSDEF(Edate_and_time); 
	EdatePtr date_component; 
	Elocal_timePtr time_component; 
};
class Edate :
		public IStepNode
{
public:
	CLASSDEF(Edate); 
	Eyear_numberPtr year_component; 
};
class Ecalendar_date :
	public  Edate
{
public:
	CLASSDEF(Ecalendar_date); 
	Eday_in_month_numberPtr day_component; 
	Emonth_in_year_numberPtr month_component; 
};
class Eordinal_date :
	public  Edate
{
public:
	CLASSDEF(Eordinal_date); 
	Eday_in_year_numberPtr day_component; 
};
class Eweek_of_year_and_day_date :
	public  Edate
{
public:
	CLASSDEF(Eweek_of_year_and_day_date); 
	Eweek_in_year_numberPtr week_component; 
	Eday_in_week_numberPtr day_component; 
};
class Elocal_time :
		public IStepNode
{
public:
	CLASSDEF(Elocal_time); 
	Ehour_in_dayPtr hour_component; 
	Eminute_in_hourPtr minute_component; 
	Esecond_in_minutePtr second_component; 
	Ecoordinated_universal_time_offsetPtr zone; 
};
class Ecoordinated_universal_time_offset :
		public IStepNode
{
public:
	CLASSDEF(Ecoordinated_universal_time_offset); 
	EIntegerPtr hour_offset; 
	EIntegerPtr minute_offset; 
	Eahead_or_behindPtr sense; 
};
class Eperson :
		public IStepNode
{
public:
	CLASSDEF(Eperson); 
	EidentifierPtr id; 
	ElabelPtr last_name; 
	ElabelPtr first_name; 
	EListT<ElabelPtr> middle_names; 
	EListT<ElabelPtr> prefix_titles; 
	EListT<ElabelPtr> suffix_titles; 
};
class Eaddress :
		public IStepNode
{
public:
	CLASSDEF(Eaddress); 
	ElabelPtr internal_location; 
	ElabelPtr street_number; 
	ElabelPtr street; 
	ElabelPtr postal_box; 
	ElabelPtr town; 
	ElabelPtr region; 
	ElabelPtr postal_code; 
	ElabelPtr country; 
	ElabelPtr facsimile_number; 
	ElabelPtr telephone_number; 
	ElabelPtr electronic_mail_address; 
	ElabelPtr telex_number; 
};
class Erepresentation :
		public IStepNode
{
public:
	CLASSDEF(Erepresentation); 
	ElabelPtr name; 
	EListT<Erepresentation_itemPtr> items; 
	Erepresentation_contextPtr context_of_items; 
};
class Eshape_representation :
	public  Erepresentation
{
public:
	CLASSDEF(Eshape_representation); 
};
class Erepresentation_item :
		public IStepNode
{
public:
	CLASSDEF(Erepresentation_item); 
	ElabelPtr name; 
};
class Egeometric_representation_item :
	public  Erepresentation_item
{
public:
	CLASSDEF(Egeometric_representation_item); 
};
class Ecurve :
	public  Egeometric_representation_item
{
public:
	CLASSDEF(Ecurve); 
};
class Ebounded_curve :
	public  Ecurve
{
public:
	CLASSDEF(Ebounded_curve); 
};
class Etrimmed_curve :
	public  Ebounded_curve
{
public:
	CLASSDEF(Etrimmed_curve); 
	EcurvePtr basis_curve; 
	EListT<Etrimming_selectPtr> trim_1; 
	EListT<Etrimming_selectPtr> trim_2; 
	EBooleanPtr sense_agreement; 
	Etrimming_preferencePtr master_representation; 
};
class Ecomposite_curve :
	public  Ebounded_curve
{
public:
	CLASSDEF(Ecomposite_curve); 
	EListT<Ecomposite_curve_segmentPtr> segments; 
	ELogicalPtr self_intersect; 
};
class Ecomposite_curve_segment :
		public IStepNode
{
public:
	CLASSDEF(Ecomposite_curve_segment); 
	Etransition_codePtr transition; 
	EBooleanPtr same_sense; 
	EcurvePtr parent_curve; 
};
class Eplacement :
	public  Egeometric_representation_item
{
public:
	CLASSDEF(Eplacement); 
	Ecartesian_pointPtr location; 
};
class Eaxis1_placement :
	public  Eplacement
{
public:
	CLASSDEF(Eaxis1_placement); 
	EdirectionPtr axis; 
};
class Eaxis2_placement_3d :
	public  Eplacement
{
public:
	CLASSDEF(Eaxis2_placement_3d); 
	EdirectionPtr axis; 
	EdirectionPtr ref_direction; 
};
class Eb_spline_curve :
	public  Ebounded_curve
{
public:
	CLASSDEF(Eb_spline_curve); 
	EIntegerPtr degree; 
	EListT<Ecartesian_pointPtr> control_points_list; 
	Eb_spline_curve_formPtr curve_form; 
	ELogicalPtr closed_curve; 
	ELogicalPtr self_intersect; 
};
class Ebezier_curve :
	public  Eb_spline_curve
{
public:
	CLASSDEF(Ebezier_curve); 
};
class Esurface :
	public  Egeometric_representation_item
{
public:
	CLASSDEF(Esurface); 
};
class Ebounded_surface :
	public  Esurface
{
public:
	CLASSDEF(Ebounded_surface); 
};
class Eb_spline_surface :
	public  Ebounded_surface
{
public:
	CLASSDEF(Eb_spline_surface); 
	EIntegerPtr u_degree; 
	EIntegerPtr v_degree; 
	std::vector< EListT<Ecartesian_pointPtr> > control_points_list; 
	Eb_spline_surface_formPtr surface_form; 
	ELogicalPtr u_closed; 
	ELogicalPtr v_closed; 
	ELogicalPtr self_intersect; 
};
class Ebezier_surface :
	public  Eb_spline_surface
{
public:
	CLASSDEF(Ebezier_surface); 
};
class Epcurve :
	public  Ecurve
{
public:
	CLASSDEF(Epcurve); 
	EsurfacePtr basis_surface; 
	Edefinitional_representationPtr reference_to_curve; 
};
class Ebounded_pcurve :
	public  Epcurve
{
public:
	CLASSDEF(Ebounded_pcurve); 
};
class Eb_spline_curve_with_knots :
	public  Eb_spline_curve
{
public:
	CLASSDEF(Eb_spline_curve_with_knots); 
	EListT<EIntegerPtr> knot_multiplicities; 
	EListT<Eparameter_valuePtr> knots; 
	Eknot_typePtr knot_spec; 
};
class Eb_spline_surface_with_knots :
	public  Eb_spline_surface
{
public:
	CLASSDEF(Eb_spline_surface_with_knots); 
	EListT<EIntegerPtr> u_multiplicities; 
	EListT<EIntegerPtr> v_multiplicities; 
	EListT<Eparameter_valuePtr> u_knots; 
	EListT<Eparameter_valuePtr> v_knots; 
	Eknot_typePtr knot_spec; 
};
class Epoint :
	public  Egeometric_representation_item
{
public:
	CLASSDEF(Epoint); 
};
class Ecartesian_point :
	public  Epoint
{
public:
	CLASSDEF(Ecartesian_point); 
	EListT<Elength_measurePtr> coordinates; 
};
class Econic :
	public  Ecurve
{
public:
	CLASSDEF(Econic); 
	Eaxis2_placement_3dPtr position; 
};
class Ecircle :
	public  Econic
{
public:
	CLASSDEF(Ecircle); 
	Epositive_length_measurePtr radius; 
};
class Edirection :
	public  Egeometric_representation_item
{
public:
	CLASSDEF(Edirection); 
	EListT<ERealPtr> direction_ratios; 
};
class Eelementary_surface :
	public  Esurface
{
public:
	CLASSDEF(Eelementary_surface); 
	Eaxis2_placement_3dPtr position; 
};
class Eellipse :
	public  Econic
{
public:
	CLASSDEF(Eellipse); 
	Epositive_length_measurePtr semi_axis_1; 
	Epositive_length_measurePtr semi_axis_2; 
};
class Erepresentation_context :
		public IStepNode
{
public:
	CLASSDEF(Erepresentation_context); 
	EidentifierPtr context_identifier; 
	EtextPtr context_type; 
};
class Egeometric_representation_context :
	public  Erepresentation_context
{
public:
	CLASSDEF(Egeometric_representation_context); 
	Edimension_countPtr coordinate_space_dimension; 
};
class Ehyperbola :
	public  Econic
{
public:
	CLASSDEF(Ehyperbola); 
	Epositive_length_measurePtr semi_axis; 
	Epositive_length_measurePtr semi_imag_axis; 
};
class Eline :
	public  Ecurve
{
public:
	CLASSDEF(Eline); 
	Ecartesian_pointPtr pnt; 
	EvectorPtr dir; 
};
class Eparabola :
	public  Econic
{
public:
	CLASSDEF(Eparabola); 
	Elength_measurePtr focal_dist; 
};
class Eplane :
	public  Eelementary_surface
{
public:
	CLASSDEF(Eplane); 
};
class Epolyline :
	public  Ebounded_curve
{
public:
	CLASSDEF(Epolyline); 
	EListT<Ecartesian_pointPtr> points; 
};
class Equasi_uniform_curve :
	public  Eb_spline_curve
{
public:
	CLASSDEF(Equasi_uniform_curve); 
};
class Equasi_uniform_surface :
	public  Eb_spline_surface
{
public:
	CLASSDEF(Equasi_uniform_surface); 
};
class Erational_b_spline_curve :
	public  Eb_spline_curve
{
public:
	CLASSDEF(Erational_b_spline_curve); 
	EListT<ERealPtr> weights_data; 
};
class Erational_b_spline_surface :
	public  Eb_spline_surface
{
public:
	CLASSDEF(Erational_b_spline_surface); 
	std::vector< EListT<ERealPtr> > weights_data; 
};
class Espherical_surface :
	public  Eelementary_surface
{
public:
	CLASSDEF(Espherical_surface); 
	Epositive_length_measurePtr radius; 
};
class Eswept_surface :
	public  Esurface
{
public:
	CLASSDEF(Eswept_surface); 
	EcurvePtr swept_curve; 
};
class Esurface_of_linear_extrusion :
	public  Eswept_surface
{
public:
	CLASSDEF(Esurface_of_linear_extrusion); 
	EvectorPtr extrusion_axis; 
};
class Esurface_of_revolution :
	public  Eswept_surface
{
public:
	CLASSDEF(Esurface_of_revolution); 
	Eaxis1_placementPtr axis_position; 
};
class Euniform_curve :
	public  Eb_spline_curve
{
public:
	CLASSDEF(Euniform_curve); 
};
class Euniform_surface :
	public  Eb_spline_surface
{
public:
	CLASSDEF(Euniform_surface); 
};
class Evector :
	public  Egeometric_representation_item
{
public:
	CLASSDEF(Evector); 
	EdirectionPtr orientation; 
	Elength_measurePtr magnitude; 
};
class Etopological_representation_item :
	public  Erepresentation_item
{
public:
	CLASSDEF(Etopological_representation_item); 
};
class Econnected_face_set :
	public  Etopological_representation_item
{
public:
	CLASSDEF(Econnected_face_set); 
	EListT<EfacePtr> cfs_faces; 
};
class Eclosed_shell :
	public  Econnected_face_set
{
public:
	CLASSDEF(Eclosed_shell); 
};
class Eedge :
	public  Etopological_representation_item
{
public:
	CLASSDEF(Eedge); 
	EvertexPtr edge_start; 
	EvertexPtr edge_end; 
};
class Eedge_curve :
	public  Eedge
{
public:
	CLASSDEF(Eedge_curve); 
	EcurvePtr edge_geometry; 
	EBooleanPtr same_sense; 
};
class Eloop :
	public  Etopological_representation_item
{
public:
	CLASSDEF(Eloop); 
};
class Eedge_loop :
	public  Eloop
{
public:
	CLASSDEF(Eedge_loop); 
};
class Eface :
	public  Etopological_representation_item
{
public:
	CLASSDEF(Eface); 
	EListT<Eface_boundPtr> bounds; 
};
class Eface_bound :
	public  Etopological_representation_item
{
public:
	CLASSDEF(Eface_bound); 
	EloopPtr bound; 
	EBooleanPtr orientation; 
};
class Eface_outer_bound :
	public  Eface_bound
{
public:
	CLASSDEF(Eface_outer_bound); 
};
class Eface_surface :
	public  Eface
{
public:
	CLASSDEF(Eface_surface); 
	EsurfacePtr face_geometry; 
	EBooleanPtr same_sense; 
};
class Eopen_shell :
	public  Econnected_face_set
{
public:
	CLASSDEF(Eopen_shell); 
};
class Eoriented_edge :
	public  Eedge
{
public:
	CLASSDEF(Eoriented_edge); 
	EedgePtr edge_element; 
	EBooleanPtr orientation; 
};
class Epath :
	public  Etopological_representation_item
{
public:
	CLASSDEF(Epath); 
	EListT<Eoriented_edgePtr> edge_list; 
};
class Evertex :
	public  Etopological_representation_item
{
public:
	CLASSDEF(Evertex); 
};
class Evertex_loop :
	public  Eloop
{
public:
	CLASSDEF(Evertex_loop); 
	EvertexPtr loop_vertex; 
};
class Evertex_point :
	public  Evertex
{
public:
	CLASSDEF(Evertex_point); 
	EpointPtr vertex_geometry; 
};
class Eblock :
	public  Egeometric_representation_item
{
public:
	CLASSDEF(Eblock); 
	Eaxis2_placement_3dPtr position; 
	Epositive_length_measurePtr x; 
	Epositive_length_measurePtr y; 
	Epositive_length_measurePtr z; 
};
class Esolid_model :
	public  Egeometric_representation_item
{
public:
	CLASSDEF(Esolid_model); 
};
class Emanifold_solid_brep :
	public  Esolid_model
{
public:
	CLASSDEF(Emanifold_solid_brep); 
	Eclosed_shellPtr outer; 
};
class Eright_circular_cylinder :
	public  Egeometric_representation_item
{
public:
	CLASSDEF(Eright_circular_cylinder); 
	Eaxis1_placementPtr position; 
	Epositive_length_measurePtr height; 
	Epositive_length_measurePtr radius; 
};
class Edefinitional_representation :
	public  Erepresentation
{
public:
	CLASSDEF(Edefinitional_representation); 
};
class Eadvanced_face :
	public  Eface_surface
{
public:
	CLASSDEF(Eadvanced_face); 
};
class Eadvanced_brep_shape_representation :
	public  Eshape_representation
{
public:
	CLASSDEF(Eadvanced_brep_shape_representation); 
};
class Etoleranced_length_measure :
		public IStepNode
{
public:
	CLASSDEF(Etoleranced_length_measure); 
	Epositive_length_measurePtr theoretical_size; 
	Etolerance_selectPtr implicit_tolerance; 
};
class Eplus_minus_value :
		public IStepNode
{
public:
	CLASSDEF(Eplus_minus_value); 
	Epositive_length_measurePtr upper_limit; 
	Epositive_length_measurePtr lower_limit; 
	EIntegerPtr significant_digits; 
};
class Elimits_and_fits :
		public IStepNode
{
public:
	CLASSDEF(Elimits_and_fits); 
	Elength_measurePtr deviation; 
	Elength_measurePtr grade; 
	Efitting_typePtr its_fitting_type; 
};
class Eproject :
		public IStepNode
{
public:
	CLASSDEF(Eproject); 
	EidentifierPtr its_id; 
	EworkplanPtr main_workplan; 
	EListT<EworkpiecePtr> its_workpieces; 
	Eperson_and_addressPtr its_owner; 
	Edate_and_timePtr its_release; 
	EapprovalPtr its_status; 
};
class Eperson_and_address :
		public IStepNode
{
public:
	CLASSDEF(Eperson_and_address); 
	EpersonPtr its_person; 
	EaddressPtr its_address; 
};
class Eworkpiece :
		public IStepNode
{
public:
	CLASSDEF(Eworkpiece); 
	EidentifierPtr its_id; 
	EmaterialPtr its_material; 
	Eshape_tolerancePtr global_tolerance; 
	EworkpiecePtr its_rawpiece; 
	Eadvanced_brep_shape_representationPtr its_geometry; 
	Ebounding_geometry_selectPtr its_bounding_geometry; 
	EListT<Ecartesian_pointPtr> clamping_positions; 
};
class Ematerial :
		public IStepNode
{
public:
	CLASSDEF(Ematerial); 
	ElabelPtr standard_identifier; 
	ElabelPtr material_identifier; 
	EListT<Eproperty_parameterPtr> material_property; 
};
class Eproperty_parameter :
		public IStepNode
{
public:
	CLASSDEF(Eproperty_parameter); 
	ElabelPtr parameter_name; 
};
class Edescriptive_parameter :
	public  Eproperty_parameter
{
public:
	CLASSDEF(Edescriptive_parameter); 
	EtextPtr descriptive_string; 
};
class Enumeric_parameter :
	public  Eproperty_parameter
{
public:
	CLASSDEF(Enumeric_parameter); 
	Eparameter_valuePtr its_parameter_value; 
	ElabelPtr its_parameter_unit; 
};
class Emanufacturing_feature :
		public IStepNode
{
public:
	CLASSDEF(Emanufacturing_feature); 
	EidentifierPtr its_id; 
	EworkpiecePtr its_workpiece; 
	EListT<Emachining_operationPtr> its_operations; 
};
class Eregion :
	public  Emanufacturing_feature
{
public:
	CLASSDEF(Eregion); 
	Eaxis2_placement_3dPtr feature_placement; 
};
class Eregion_projection :
	public  Eregion
{
public:
	CLASSDEF(Eregion_projection); 
	Ebounded_curvePtr proj_curve; 
	EdirectionPtr proj_dir; 
	Etoleranced_length_measurePtr depth; 
};
class Eregion_surface_list :
	public  Eregion
{
public:
	CLASSDEF(Eregion_surface_list); 
	EListT<Ebounded_surfacePtr> surface_list; 
};
class Etopological_region :
	public  Eregion
{
public:
	CLASSDEF(Etopological_region); 
};
class Etwo5d_manufacturing_feature :
	public  Emanufacturing_feature
{
public:
	CLASSDEF(Etwo5d_manufacturing_feature); 
	Eaxis2_placement_3dPtr feature_placement; 
};
class Emachining_feature :
	public  Etwo5d_manufacturing_feature
{
public:
	CLASSDEF(Emachining_feature); 
	Eelementary_surfacePtr depth; 
};
class Eplanar_face :
	public  Emachining_feature
{
public:
	CLASSDEF(Eplanar_face); 
	Elinear_pathPtr course_of_travel; 
	Elinear_profilePtr removal_boundary; 
	Eclosed_profilePtr face_boundary; 
	EListT<EbossPtr> its_boss; 
};
class Epocket :
	public  Emachining_feature
{
public:
	CLASSDEF(Epocket); 
	EListT<EbossPtr> its_boss; 
	Eplane_angle_measurePtr slope; 
	Epocket_bottom_conditionPtr bottom_condition; 
	Etoleranced_length_measurePtr planar_radius; 
	Etoleranced_length_measurePtr orthogonal_radius; 
};
class Eclosed_pocket :
	public  Epocket
{
public:
	CLASSDEF(Eclosed_pocket); 
	Eclosed_profilePtr feature_boundary; 
};
class Eopen_pocket :
	public  Epocket
{
public:
	CLASSDEF(Eopen_pocket); 
	Eopen_profilePtr open_boundary; 
	Eopen_profilePtr wall_boundary; 
};
class Epocket_bottom_condition :
		public IStepNode
{
public:
	CLASSDEF(Epocket_bottom_condition); 
};
class Ethrough_pocket_bottom_condition :
	public  Epocket_bottom_condition
{
public:
	CLASSDEF(Ethrough_pocket_bottom_condition); 
};
class Eplanar_pocket_bottom_condition :
	public  Epocket_bottom_condition
{
public:
	CLASSDEF(Eplanar_pocket_bottom_condition); 
};
class Eradiused_pocket_bottom_condition :
	public  Epocket_bottom_condition
{
public:
	CLASSDEF(Eradiused_pocket_bottom_condition); 
	Ecartesian_pointPtr floor_radius_center; 
	Etoleranced_length_measurePtr floor_radius; 
};
class Egeneral_pocket_bottom_condition :
	public  Epocket_bottom_condition
{
public:
	CLASSDEF(Egeneral_pocket_bottom_condition); 
	EregionPtr shape; 
};
class Eslot :
	public  Emachining_feature
{
public:
	CLASSDEF(Eslot); 
	Etravel_pathPtr course_of_travel; 
	Eopen_profilePtr swept_shape; 
	EListT<Eslot_end_typePtr> end_conditions; 
};
class Eslot_end_type :
		public IStepNode
{
public:
	CLASSDEF(Eslot_end_type); 
};
class Ewoodruff_slot_end_type :
	public  Eslot_end_type
{
public:
	CLASSDEF(Ewoodruff_slot_end_type); 
	Etoleranced_length_measurePtr radius; 
};
class Eradiused_slot_end_type :
	public  Eslot_end_type
{
public:
	CLASSDEF(Eradiused_slot_end_type); 
};
class Eflat_slot_end_type :
	public  Eslot_end_type
{
public:
	CLASSDEF(Eflat_slot_end_type); 
	Etoleranced_length_measurePtr corner_radius1; 
	Etoleranced_length_measurePtr corner_radius2; 
};
class Eloop_slot_end_type :
	public  Eslot_end_type
{
public:
	CLASSDEF(Eloop_slot_end_type); 
};
class Eopen_slot_end_type :
	public  Eslot_end_type
{
public:
	CLASSDEF(Eopen_slot_end_type); 
};
class Estep :
	public  Emachining_feature
{
public:
	CLASSDEF(Estep); 
	Elinear_pathPtr open_boundary; 
	Evee_profilePtr wall_boundary; 
	EListT<EbossPtr> its_boss; 
};
class Eprofile_feature :
	public  Emachining_feature
{
public:
	CLASSDEF(Eprofile_feature); 
	Elinear_pathPtr profile_swept_shape; 
};
class Egeneral_outside_profile :
	public  Eprofile_feature
{
public:
	CLASSDEF(Egeneral_outside_profile); 
	EprofilePtr feature_boundary; 
};
class Eshape_profile :
	public  Eprofile_feature
{
public:
	CLASSDEF(Eshape_profile); 
	Eprofile_selectPtr floor_condition; 
	EdirectionPtr removal_direction; 
};
class Ethrough_profile_floor :
		public IStepNode
{
public:
	CLASSDEF(Ethrough_profile_floor); 
};
class Eprofile_floor :
		public IStepNode
{
public:
	CLASSDEF(Eprofile_floor); 
	Enumeric_parameterPtr floor_radius; 
	EBooleanPtr start_or_end; 
};
class Egeneral_profile_floor :
	public  Eprofile_floor
{
public:
	CLASSDEF(Egeneral_profile_floor); 
	EfacePtr floor; 
};
class Eplanar_profile_floor :
	public  Eprofile_floor
{
public:
	CLASSDEF(Eplanar_profile_floor); 
	EplanePtr floor; 
};
class Egeneral_shape_profile :
	public  Eshape_profile
{
public:
	CLASSDEF(Egeneral_shape_profile); 
	EprofilePtr profile_boundary; 
};
class Epartial_circular_shape_profile :
	public  Eshape_profile
{
public:
	CLASSDEF(Epartial_circular_shape_profile); 
	Epartial_circular_profilePtr open_boundary; 
};
class Ecircular_closed_shape_profile :
	public  Eshape_profile
{
public:
	CLASSDEF(Ecircular_closed_shape_profile); 
	Ecircular_closed_profilePtr closed_boundary; 
};
class Erectangular_open_shape_profile :
	public  Eshape_profile
{
public:
	CLASSDEF(Erectangular_open_shape_profile); 
	Esquare_u_profilePtr open_boundary; 
};
class Erectangular_closed_shape_profile :
	public  Eshape_profile
{
public:
	CLASSDEF(Erectangular_closed_shape_profile); 
	Erectangular_closed_profilePtr closed_boundary; 
};
class Eround_hole :
	public  Emachining_feature
{
public:
	CLASSDEF(Eround_hole); 
	Etoleranced_length_measurePtr diameter; 
	Etaper_selectPtr change_in_diameter; 
	Ehole_bottom_conditionPtr bottom_condition; 
};
class Ediameter_taper :
		public IStepNode
{
public:
	CLASSDEF(Ediameter_taper); 
	Etoleranced_length_measurePtr final_diameter; 
};
class Eangle_taper :
		public IStepNode
{
public:
	CLASSDEF(Eangle_taper); 
	Eplane_angle_measurePtr angle; 
};
class Ehole_bottom_condition :
		public IStepNode
{
public:
	CLASSDEF(Ehole_bottom_condition); 
};
class Ethrough_bottom_condition :
	public  Ehole_bottom_condition
{
public:
	CLASSDEF(Ethrough_bottom_condition); 
};
class Eblind_bottom_condition :
	public  Ehole_bottom_condition
{
public:
	CLASSDEF(Eblind_bottom_condition); 
};
class Eflat_hole_bottom :
	public  Eblind_bottom_condition
{
public:
	CLASSDEF(Eflat_hole_bottom); 
};
class Eflat_with_radius_hole_bottom :
	public  Eblind_bottom_condition
{
public:
	CLASSDEF(Eflat_with_radius_hole_bottom); 
	Etoleranced_length_measurePtr corner_radius; 
};
class Espherical_hole_bottom :
	public  Eblind_bottom_condition
{
public:
	CLASSDEF(Espherical_hole_bottom); 
	Etoleranced_length_measurePtr radius; 
};
class Econical_hole_bottom :
	public  Eblind_bottom_condition
{
public:
	CLASSDEF(Econical_hole_bottom); 
	Eplane_angle_measurePtr tip_angle; 
	Etoleranced_length_measurePtr tip_radius; 
};
class Etoolpath_feature :
	public  Emachining_feature
{
public:
	CLASSDEF(Etoolpath_feature); 
};
class Eboss :
	public  Emachining_feature
{
public:
	CLASSDEF(Eboss); 
	Eclosed_profilePtr its_boundary; 
	Eplane_angle_measurePtr slope; 
};
class Espherical_cap :
	public  Emachining_feature
{
public:
	CLASSDEF(Espherical_cap); 
	Enumeric_parameterPtr internal_angle; 
	Enumeric_parameterPtr radius; 
};
class Erounded_end :
	public  Emachining_feature
{
public:
	CLASSDEF(Erounded_end); 
	Elinear_pathPtr course_of_travel; 
	Epartial_circular_profilePtr partial_circular_boundary; 
};
class Ecompound_feature :
	public  Etwo5d_manufacturing_feature
{
public:
	CLASSDEF(Ecompound_feature); 
	EListT<Ecompound_feature_selectPtr> elements; 
};
class Ecounterbore_hole :
	public  Ecompound_feature
{
public:
	CLASSDEF(Ecounterbore_hole); 
};
class Ecountersunk_hole :
	public  Ecompound_feature
{
public:
	CLASSDEF(Ecountersunk_hole); 
};
class Ereplicate_feature :
	public  Etwo5d_manufacturing_feature
{
public:
	CLASSDEF(Ereplicate_feature); 
	Etwo5d_manufacturing_featurePtr replicate_base_feature; 
};
class Ecircular_pattern :
	public  Ereplicate_feature
{
public:
	CLASSDEF(Ecircular_pattern); 
	Eplane_angle_measurePtr angle_increment; 
	EIntegerPtr number_of_feature; 
	EListT<Ecircular_offsetPtr> relocated_base_feature; 
	EListT<Ecircular_omitPtr> missing_base_feature; 
	Etoleranced_length_measurePtr base_feature_diameter; 
	Eplane_angle_measurePtr base_feature_rotation; 
};
class Ecircular_offset :
		public IStepNode
{
public:
	CLASSDEF(Ecircular_offset); 
	Eplane_angle_measurePtr angular_offset; 
	EIntegerPtr index; 
};
class Ecircular_omit :
		public IStepNode
{
public:
	CLASSDEF(Ecircular_omit); 
	EIntegerPtr index; 
};
class Erectangular_pattern :
	public  Ereplicate_feature
{
public:
	CLASSDEF(Erectangular_pattern); 
	Etoleranced_length_measurePtr spacing; 
	EdirectionPtr its_direction; 
	EIntegerPtr number_of_rows; 
	EIntegerPtr number_of_columns; 
	Etoleranced_length_measurePtr row_spacing; 
	EdirectionPtr row_layout_direction; 
	EListT<Erectangular_offsetPtr> relocated_base_feature; 
	EListT<Erectangular_omitPtr> missing_base_feature; 
};
class Erectangular_offset :
		public IStepNode
{
public:
	CLASSDEF(Erectangular_offset); 
	EdirectionPtr offset_direction; 
	Elength_measurePtr offset_distance; 
	EIntegerPtr row_index; 
	EIntegerPtr column_index; 
};
class Erectangular_omit :
		public IStepNode
{
public:
	CLASSDEF(Erectangular_omit); 
	EIntegerPtr row_index; 
	EIntegerPtr column_index; 
};
class Egeneral_pattern :
	public  Ereplicate_feature
{
public:
	CLASSDEF(Egeneral_pattern); 
	EListT<Eaxis2_placement_3dPtr> replicate_locations; 
};
class Etransition_feature :
	public  Emanufacturing_feature
{
public:
	CLASSDEF(Etransition_feature); 
	Emachining_featurePtr first_feature; 
	Emachining_featurePtr second_feature; 
};
class Echamfer :
	public  Etransition_feature
{
public:
	CLASSDEF(Echamfer); 
	Eplane_angle_measurePtr angle_to_plane; 
	Etoleranced_length_measurePtr first_offset_amount; 
};
class Eedge_round :
	public  Etransition_feature
{
public:
	CLASSDEF(Eedge_round); 
	Etoleranced_length_measurePtr radius; 
	Etoleranced_length_measurePtr first_offset_amount; 
	Etoleranced_length_measurePtr second_offset_amount; 
};
class Ethread :
	public  Emachining_feature
{
public:
	CLASSDEF(Ethread); 
	Epartial_area_definitionPtr partial_profile; 
	EListT<Emachining_featurePtr> applied_shape; 
	EBooleanPtr inner_or_outer_thread; 
	Edescriptive_parameterPtr qualifier; 
	Edescriptive_parameterPtr fit_class; 
	Edescriptive_parameterPtr form; 
	Elength_measurePtr major_diameter; 
	Enumeric_parameterPtr number_of_threads; 
	Edescriptive_parameterPtr thread_hand; 
};
class Epartial_area_definition :
		public IStepNode
{
public:
	CLASSDEF(Epartial_area_definition); 
	Elength_measurePtr effective_length; 
	Eaxis2_placement_3dPtr placement; 
	Elength_measurePtr maximum_length; 
};
class Ecatalogue_thread :
	public  Ethread
{
public:
	CLASSDEF(Ecatalogue_thread); 
	EspecificationPtr documentation; 
};
class Especification :
		public IStepNode
{
public:
	CLASSDEF(Especification); 
	EListT<Especification_usage_constraintPtr> constraint; 
	EtextPtr specification_id; 
	EtextPtr specification_description; 
	EtextPtr specification_class; 
};
class Especification_usage_constraint :
		public IStepNode
{
public:
	CLASSDEF(Especification_usage_constraint); 
	EtextPtr element; 
	EtextPtr class_id; 
};
class Edefined_thread :
	public  Ethread
{
public:
	CLASSDEF(Edefined_thread); 
	Elength_measurePtr pitch_diameter; 
	Elength_measurePtr minor_diameter; 
	Elength_measurePtr crest; 
};
class Eprofile :
		public IStepNode
{
public:
	CLASSDEF(Eprofile); 
	Eaxis2_placement_3dPtr placement; 
};
class Eopen_profile :
	public  Eprofile
{
public:
	CLASSDEF(Eopen_profile); 
};
class Elinear_profile :
	public  Eopen_profile
{
public:
	CLASSDEF(Elinear_profile); 
	Enumeric_parameterPtr profile_length; 
};
class Esquare_u_profile :
	public  Eopen_profile
{
public:
	CLASSDEF(Esquare_u_profile); 
	Etoleranced_length_measurePtr width; 
	Etoleranced_length_measurePtr first_radius; 
	Eplane_angle_measurePtr first_angle; 
	Etoleranced_length_measurePtr second_radius; 
	Eplane_angle_measurePtr second_angle; 
};
class Erounded_u_profile :
	public  Eopen_profile
{
public:
	CLASSDEF(Erounded_u_profile); 
	Etoleranced_length_measurePtr width; 
};
class Etee_profile :
	public  Eopen_profile
{
public:
	CLASSDEF(Etee_profile); 
	Eplane_angle_measurePtr first_angle; 
	Eplane_angle_measurePtr second_angle; 
	Etoleranced_length_measurePtr cross_bar_width; 
	Etoleranced_length_measurePtr cross_bar_depth; 
	Etoleranced_length_measurePtr radius; 
	Etoleranced_length_measurePtr width; 
	Etoleranced_length_measurePtr first_offset; 
	Etoleranced_length_measurePtr second_offset; 
};
class Evee_profile :
	public  Eopen_profile
{
public:
	CLASSDEF(Evee_profile); 
	Etoleranced_length_measurePtr profile_radius; 
	Eplane_angle_measurePtr profile_angle; 
	Eplane_angle_measurePtr tilt_angle; 
};
class Epartial_circular_profile :
	public  Eopen_profile
{
public:
	CLASSDEF(Epartial_circular_profile); 
	Etoleranced_length_measurePtr radius; 
	Eplane_angle_measurePtr sweep_angle; 
};
class Egeneral_profile :
	public  Eopen_profile
{
public:
	CLASSDEF(Egeneral_profile); 
	Ebounded_curvePtr its_profile; 
};
class Eclosed_profile :
	public  Eprofile
{
public:
	CLASSDEF(Eclosed_profile); 
};
class Erectangular_closed_profile :
	public  Eclosed_profile
{
public:
	CLASSDEF(Erectangular_closed_profile); 
	Etoleranced_length_measurePtr profile_width; 
	Etoleranced_length_measurePtr profile_length; 
};
class Ecircular_closed_profile :
	public  Eclosed_profile
{
public:
	CLASSDEF(Ecircular_closed_profile); 
	Etoleranced_length_measurePtr diameter; 
};
class Engon_profile :
	public  Eclosed_profile
{
public:
	CLASSDEF(Engon_profile); 
	Etoleranced_length_measurePtr diameter; 
	EIntegerPtr number_of_sides; 
	EBooleanPtr circumscribed_or_across_flats; 
};
class Egeneral_closed_profile :
	public  Eclosed_profile
{
public:
	CLASSDEF(Egeneral_closed_profile); 
	Ebounded_curvePtr closed_profile_shape; 
};
class Etravel_path :
		public IStepNode
{
public:
	CLASSDEF(Etravel_path); 
	Eaxis2_placement_3dPtr placement; 
};
class Egeneral_path :
	public  Etravel_path
{
public:
	CLASSDEF(Egeneral_path); 
	Ebounded_curvePtr swept_path; 
};
class Elinear_path :
	public  Etravel_path
{
public:
	CLASSDEF(Elinear_path); 
	Etoleranced_length_measurePtr distance; 
	EdirectionPtr its_direction; 
};
class Ecircular_path :
	public  Etravel_path
{
public:
	CLASSDEF(Ecircular_path); 
	Etoleranced_length_measurePtr radius; 
};
class Ecomplete_circular_path :
	public  Ecircular_path
{
public:
	CLASSDEF(Ecomplete_circular_path); 
};
class Epartial_circular_path :
	public  Ecircular_path
{
public:
	CLASSDEF(Epartial_circular_path); 
	Eplane_angle_measurePtr sweep_angle; 
};
class Esurface_texture_parameter :
		public IStepNode
{
public:
	CLASSDEF(Esurface_texture_parameter); 
	Eparameter_valuePtr its_value; 
	ElabelPtr parameter_name; 
	EidentifierPtr measuring_method; 
	EidentifierPtr parameter_index; 
	EListT<Emachined_surfacePtr> applied_surfaces; 
};
class Emachined_surface :
		public IStepNode
{
public:
	CLASSDEF(Emachined_surface); 
	Emachining_featurePtr its_machining_feature; 
	Ebottom_or_sidePtr surface_element; 
};
class Eexecutable :
		public IStepNode
{
public:
	CLASSDEF(Eexecutable); 
	EidentifierPtr its_id; 
};
class Eworkingstep :
	public  Eexecutable
{
public:
	CLASSDEF(Eworkingstep); 
	Eelementary_surfacePtr its_secplane; 
};
class Emachining_workingstep :
	public  Eworkingstep
{
public:
	CLASSDEF(Emachining_workingstep); 
	Emanufacturing_featurePtr its_feature; 
	Emachining_operationPtr its_operation; 
	Ein_process_geometryPtr its_effect; 
};
class Ein_process_geometry :
		public IStepNode
{
public:
	CLASSDEF(Ein_process_geometry); 
	Eadvanced_brep_shape_representationPtr as_is; 
	Eadvanced_brep_shape_representationPtr to_be; 
	Eadvanced_brep_shape_representationPtr removal; 
};
class Erapid_movement :
	public  Eworkingstep
{
public:
	CLASSDEF(Erapid_movement); 
};
class Ereturn_home :
	public  Erapid_movement
{
public:
	CLASSDEF(Ereturn_home); 
};
class Etouch_probing :
	public  Eworkingstep
{
public:
	CLASSDEF(Etouch_probing); 
	Enc_variablePtr measured_offset; 
};
class Eworkpiece_probing :
	public  Etouch_probing
{
public:
	CLASSDEF(Eworkpiece_probing); 
	Eaxis2_placement_3dPtr start_position; 
	EworkpiecePtr its_workpiece; 
	EdirectionPtr its_direction; 
	Etoleranced_length_measurePtr expected_value; 
	Etouch_probePtr its_probe; 
};
class Eworkpiece_complete_probing :
	public  Etouch_probing
{
public:
	CLASSDEF(Eworkpiece_complete_probing); 
	EworkpiecePtr its_workpiece; 
	Etoleranced_length_measurePtr probing_distance; 
	Etouch_probePtr its_probe; 
	Eoffset_vectorPtr computed_offset; 
};
class Etouch_probe :
		public IStepNode
{
public:
	CLASSDEF(Etouch_probe); 
	EidentifierPtr its_id; 
};
class Eoffset_vector :
		public IStepNode
{
public:
	CLASSDEF(Eoffset_vector); 
	EListT<Enc_variablePtr> translate; 
	EListT<Enc_variablePtr> rotate; 
};
class Etool_probing :
	public  Etouch_probing
{
public:
	CLASSDEF(Etool_probing); 
	Ecartesian_pointPtr offset; 
	Elength_measurePtr max_wear; 
	Emachining_toolPtr its_tool; 
};
class Emachining_tool :
		public IStepNode
{
public:
	CLASSDEF(Emachining_tool); 
	ElabelPtr its_id; 
};
class Ecutting_tool :
	public  Emachining_tool
{
public:
	CLASSDEF(Ecutting_tool); 
	Etool_bodyPtr its_tool_body; 
	EListT<Ecutting_componentPtr> its_cutting_edge; 
	Elength_measurePtr overall_assembly_length; 
};
class Etool_body :
		public IStepNode
{
public:
	CLASSDEF(Etool_body); 
};
class Ecutting_component :
		public IStepNode
{
public:
	CLASSDEF(Ecutting_component); 
	Elength_measurePtr tool_offset_length; 
	EmaterialPtr its_material; 
	Ecutting_edge_technological_dataPtr technological_data; 
	Etime_measurePtr expected_tool_life; 
	Emilling_technologyPtr its_technology; 
};
class Ecutting_edge_technological_data :
		public IStepNode
{
public:
	CLASSDEF(Ecutting_edge_technological_data); 
	Eplane_angle_measurePtr cutting_angle; 
	Eplane_angle_measurePtr free_angle; 
	Eplane_angle_measurePtr aux_angle; 
};
class Etool_length_probing :
	public  Etool_probing
{
public:
	CLASSDEF(Etool_length_probing); 
};
class Etool_radius_probing :
	public  Etool_probing
{
public:
	CLASSDEF(Etool_radius_probing); 
};
class Enc_function :
	public  Eexecutable
{
public:
	CLASSDEF(Enc_function); 
};
class Edisplay_message :
	public  Enc_function
{
public:
	CLASSDEF(Edisplay_message); 
	EtextPtr its_text; 
};
class Eoptional_stop :
	public  Enc_function
{
public:
	CLASSDEF(Eoptional_stop); 
};
class Eprogram_stop :
	public  Enc_function
{
public:
	CLASSDEF(Eprogram_stop); 
};
class Eset_mark :
	public  Enc_function
{
public:
	CLASSDEF(Eset_mark); 
};
class Ewait_for_mark :
	public  Enc_function
{
public:
	CLASSDEF(Ewait_for_mark); 
	EchannelPtr its_channel; 
};
class Eprogram_structure :
	public  Eexecutable
{
public:
	CLASSDEF(Eprogram_structure); 
};
class Eworkplan :
	public  Eprogram_structure
{
public:
	CLASSDEF(Eworkplan); 
	EListT<EexecutablePtr> its_elements; 
	EchannelPtr its_channel; 
	EsetupPtr its_setup; 
	Ein_process_geometryPtr its_effect; 
};
class Echannel :
		public IStepNode
{
public:
	CLASSDEF(Echannel); 
	EidentifierPtr its_id; 
};
class Esetup :
		public IStepNode
{
public:
	CLASSDEF(Esetup); 
	EidentifierPtr its_id; 
	Eaxis2_placement_3dPtr its_origin; 
	Eelementary_surfacePtr its_secplane; 
	EListT<Eworkpiece_setupPtr> its_workpiece_setup; 
};
class Eworkpiece_setup :
		public IStepNode
{
public:
	CLASSDEF(Eworkpiece_setup); 
	EworkpiecePtr its_workpiece; 
	Eaxis2_placement_3dPtr its_origin; 
	Eoffset_vectorPtr its_offset; 
	Erestricted_area_selectPtr its_restricted_area; 
	EListT<Esetup_instructionPtr> its_instructions; 
};
class Esetup_instruction :
		public IStepNode
{
public:
	CLASSDEF(Esetup_instruction); 
	EtextPtr description; 
	EidentifierPtr external_document; 
};
class Eparallel :
	public  Eprogram_structure
{
public:
	CLASSDEF(Eparallel); 
	EListT<EexecutablePtr> branches; 
};
class Enon_sequential :
	public  Eprogram_structure
{
public:
	CLASSDEF(Enon_sequential); 
	EListT<EexecutablePtr> its_elements; 
};
class Eselective :
	public  Eprogram_structure
{
public:
	CLASSDEF(Eselective); 
	EListT<EexecutablePtr> its_elements; 
};
class Eif_statement :
	public  Eprogram_structure
{
public:
	CLASSDEF(Eif_statement); 
	Eboolean_expressionPtr condition; 
	EexecutablePtr true_branch; 
	EexecutablePtr false_branch; 
};
class Ewhile_statement :
	public  Eprogram_structure
{
public:
	CLASSDEF(Ewhile_statement); 
	Eboolean_expressionPtr condition; 
	EexecutablePtr body; 
};
class Eassignment :
	public  Eprogram_structure
{
public:
	CLASSDEF(Eassignment); 
	Enc_variablePtr its_lvalue; 
	ErvaluePtr its_rvalue; 
};
class Enc_variable :
		public IStepNode
{
public:
	CLASSDEF(Enc_variable); 
	ElabelPtr its_name; 
	ENumberPtr initial_value; 
};
class Enc_constant :
		public IStepNode
{
public:
	CLASSDEF(Enc_constant); 
	ElabelPtr its_name; 
	ENumberPtr its_value; 
};
class Eboolean_expression :
		public IStepNode
{
public:
	CLASSDEF(Eboolean_expression); 
};
class Eunary_boolean_expression :
	public  Eboolean_expression
{
public:
	CLASSDEF(Eunary_boolean_expression); 
	Eboolean_expressionPtr operand; 
};
class Enot_expression :
	public  Eunary_boolean_expression
{
public:
	CLASSDEF(Enot_expression); 
};
class Ebinary_boolean_expression :
	public  Eboolean_expression
{
public:
	CLASSDEF(Ebinary_boolean_expression); 
	Eboolean_expressionPtr operand1; 
	Eboolean_expressionPtr operand2; 
};
class Exor_expression :
	public  Ebinary_boolean_expression
{
public:
	CLASSDEF(Exor_expression); 
};
class Emultiple_arity_boolean_expression :
	public  Eboolean_expression
{
public:
	CLASSDEF(Emultiple_arity_boolean_expression); 
	EListT<Eboolean_expressionPtr> operands; 
};
class Eand_expression :
	public  Emultiple_arity_boolean_expression
{
public:
	CLASSDEF(Eand_expression); 
};
class Eor_expression :
	public  Emultiple_arity_boolean_expression
{
public:
	CLASSDEF(Eor_expression); 
};
class Ecomparison_expression :
	public  Eboolean_expression
{
public:
	CLASSDEF(Ecomparison_expression); 
	Enc_variablePtr operand1; 
	ErvaluePtr operand2; 
};
class Ecomparison_equal :
	public  Ecomparison_expression
{
public:
	CLASSDEF(Ecomparison_equal); 
};
class Ecomparison_not_equal :
	public  Ecomparison_expression
{
public:
	CLASSDEF(Ecomparison_not_equal); 
};
class Ecomparison_greater :
	public  Ecomparison_expression
{
public:
	CLASSDEF(Ecomparison_greater); 
};
class Ecomparison_greater_equal :
	public  Ecomparison_expression
{
public:
	CLASSDEF(Ecomparison_greater_equal); 
};
class Ecomparison_less :
	public  Ecomparison_expression
{
public:
	CLASSDEF(Ecomparison_less); 
};
class Ecomparison_less_equal :
	public  Ecomparison_expression
{
public:
	CLASSDEF(Ecomparison_less_equal); 
};
class Eoperation :
		public IStepNode
{
public:
	CLASSDEF(Eoperation); 
	Etoolpath_listPtr its_toolpath; 
	Etool_directionPtr its_tool_direction; 
};
class Etoolpath_list :
		public IStepNode
{
public:
	CLASSDEF(Etoolpath_list); 
	EListT<EtoolpathPtr> its_list; 
};
class Etool_direction :
		public IStepNode
{
public:
	CLASSDEF(Etool_direction); 
};
class Etwo_axes :
	public  Etool_direction
{
public:
	CLASSDEF(Etwo_axes); 
};
class Ethree_axes :
	public  Etool_direction
{
public:
	CLASSDEF(Ethree_axes); 
};
class Emachining_operation :
	public  Eoperation
{
public:
	CLASSDEF(Emachining_operation); 
	EidentifierPtr its_id; 
	Elength_measurePtr retract_plane; 
	Ecartesian_pointPtr start_point; 
	Emachining_toolPtr its_tool; 
	EtechnologyPtr its_technology; 
	Emachine_functionsPtr its_machine_functions; 
};
class Etechnology :
		public IStepNode
{
public:
	CLASSDEF(Etechnology); 
	Espeed_measurePtr feedrate; 
	Etool_reference_pointPtr feedrate_reference; 
};
class Emachine_functions :
		public IStepNode
{
public:
	CLASSDEF(Emachine_functions); 
};
class Etoolpath :
		public IStepNode
{
public:
	CLASSDEF(Etoolpath); 
	EBooleanPtr its_priority; 
	Etoolpath_typePtr its_type; 
	Etoolpath_speedprofilePtr its_speed; 
	EtechnologyPtr its_technology; 
	Emachine_functionsPtr its_machine_functions; 
};
class Etoolpath_speed :
		public IStepNode
{
public:
	CLASSDEF(Etoolpath_speed); 
	Eb_spline_curvePtr speed; 
};
class Efeedstop :
	public  Etoolpath
{
public:
	CLASSDEF(Efeedstop); 
	Etime_measurePtr dwell; 
};
class Etrajectory :
	public  Etoolpath
{
public:
	CLASSDEF(Etrajectory); 
	EBooleanPtr its_direction; 
};
class Ecutter_location_trajectory :
	public  Etrajectory
{
public:
	CLASSDEF(Ecutter_location_trajectory); 
	Ebounded_curvePtr basiccurve; 
	Ebounded_curvePtr its_toolaxis; 
	Ebounded_curvePtr surface_normal; 
};
class Ecutter_contact_trajectory :
	public  Etrajectory
{
public:
	CLASSDEF(Ecutter_contact_trajectory); 
	Ecurve_with_surface_normalPtr basiccurve; 
	Ebounded_curvePtr its_toolaxis; 
	Econtact_typePtr its_contact_type; 
};
class Ecurve_with_normal_vector :
		public IStepNode
{
public:
	CLASSDEF(Ecurve_with_normal_vector); 
	Ebounded_curvePtr basiccurve; 
	Ebounded_curvePtr surface_normal; 
};
class Eaxis_trajectory :
	public  Etrajectory
{
public:
	CLASSDEF(Eaxis_trajectory); 
	EListT<EidentifierPtr> axis_list; 
	EListT<Ebounded_curvePtr> commands; 
};
class Eparameterised_path :
	public  Etoolpath
{
public:
	CLASSDEF(Eparameterised_path); 
};
class Econnector :
	public  Eparameterised_path
{
public:
	CLASSDEF(Econnector); 
};
class Econnect_secplane :
	public  Econnector
{
public:
	CLASSDEF(Econnect_secplane); 
	EdirectionPtr up_dir; 
	EdirectionPtr down_dir; 
};
class Econnect_direct :
	public  Econnector
{
public:
	CLASSDEF(Econnect_direct); 
};
class Eapproach_lift_path :
	public  Eparameterised_path
{
public:
	CLASSDEF(Eapproach_lift_path); 
	Ecartesian_pointPtr fix_point; 
	EdirectionPtr fix_point_dir; 
};
class Eap_lift_path_angle :
	public  Eapproach_lift_path
{
public:
	CLASSDEF(Eap_lift_path_angle); 
	Eplane_angle_measurePtr angle; 
	Epositive_length_measurePtr benddist; 
};
class Eap_lift_path_tangent :
	public  Eapproach_lift_path
{
public:
	CLASSDEF(Eap_lift_path_tangent); 
	Epositive_length_measurePtr radius; 
};
class Emilling_cutting_tool :
	public  Ecutting_tool
{
public:
	CLASSDEF(Emilling_cutting_tool); 
	EdirectionPtr direction_for_spindle_orientation; 
	Elength_measurePtr tool_holder_diameter_for_spindle_orientation; 
};
class Emilling_tool_body :
	public  Etool_body
{
public:
	CLASSDEF(Emilling_tool_body); 
	Emilling_tool_dimensionPtr dimension; 
	EIntegerPtr number_of_teeth; 
	EhandPtr hand_of_cut; 
	EBooleanPtr coolant_through_tool; 
	Elength_measurePtr pilot_length; 
};
class Emilling_tool_dimension :
		public IStepNode
{
public:
	CLASSDEF(Emilling_tool_dimension); 
	Elength_measurePtr diameter; 
	Eplane_angle_measurePtr tool_top_angle; 
	Eplane_angle_measurePtr tool_circumference_angle; 
	Elength_measurePtr cutting_edge_length; 
	Elength_measurePtr edge_radius; 
	Elength_measurePtr edge_center_vertical; 
	Elength_measurePtr edge_center_horizontal; 
};
class Ecenter_drill :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Ecenter_drill); 
};
class Ecountersink :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Ecountersink); 
	Elength_measurePtr countersink_radius; 
};
class Ebackside_countersink :
	public  Ecountersink
{
public:
	CLASSDEF(Ebackside_countersink); 
};
class Edrill :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Edrill); 
};
class Etwist_drill :
	public  Edrill
{
public:
	CLASSDEF(Etwist_drill); 
};
class Etapered_drill :
	public  Etwist_drill
{
public:
	CLASSDEF(Etapered_drill); 
	Eplane_angle_measurePtr taper_angle; 
};
class Espade_drill :
	public  Edrill
{
public:
	CLASSDEF(Espade_drill); 
};
class Emilling_cutter :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Emilling_cutter); 
};
class Efacemill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Efacemill); 
};
class Eendmill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Eendmill); 
};
class Etapered_endmill :
	public  Eendmill
{
public:
	CLASSDEF(Etapered_endmill); 
	Eplane_angle_measurePtr taper_angle; 
};
class Eball_endmill :
	public  Eendmill
{
public:
	CLASSDEF(Eball_endmill); 
};
class Ebullnose_endmill :
	public  Eendmill
{
public:
	CLASSDEF(Ebullnose_endmill); 
};
class Et_slot_mill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Et_slot_mill); 
	Elength_measurePtr cutting_thickness; 
};
class Edovetail_mill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Edovetail_mill); 
	Eplane_angle_measurePtr included_angle; 
};
class Ewoodruff_keyseat_mill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Ewoodruff_keyseat_mill); 
	Elength_measurePtr cutter_width; 
};
class Eside_mill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Eside_mill); 
	Elength_measurePtr cutter_width; 
};
class Ethread_mill :
	public  Emilling_cutter
{
public:
	CLASSDEF(Ethread_mill); 
};
class Etap :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Etap); 
};
class Etapered_tap :
	public  Etap
{
public:
	CLASSDEF(Etapered_tap); 
	Eplane_angle_measurePtr taper_angle; 
};
class Ecombined_drill_and_tap :
	public  Etap
{
public:
	CLASSDEF(Ecombined_drill_and_tap); 
	Elength_measurePtr drill_length; 
};
class Ethreading_tool :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Ethreading_tool); 
};
class Ecounterbore :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Ecounterbore); 
};
class Ebackside_counterbore :
	public  Ecounterbore
{
public:
	CLASSDEF(Ebackside_counterbore); 
};
class Ereamer :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Ereamer); 
};
class Etapered_reamer :
	public  Ereamer
{
public:
	CLASSDEF(Etapered_reamer); 
	Eplane_angle_measurePtr taper_angle; 
};
class Ecombined_drill_and_reamer :
	public  Ereamer
{
public:
	CLASSDEF(Ecombined_drill_and_reamer); 
	Elength_measurePtr drill_length; 
};
class Eboring_tool :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Eboring_tool); 
};
class Euser_defined_tool :
	public  Emilling_tool_body
{
public:
	CLASSDEF(Euser_defined_tool); 
	ElabelPtr identifier; 
};
class Eexchange_pallet :
	public  Enc_function
{
public:
	CLASSDEF(Eexchange_pallet); 
};
class Eindex_pallet :
	public  Enc_function
{
public:
	CLASSDEF(Eindex_pallet); 
	EIntegerPtr its_index; 
};
class Eindex_table :
	public  Enc_function
{
public:
	CLASSDEF(Eindex_table); 
	EIntegerPtr its_index; 
};
class Eload_tool :
	public  Enc_function
{
public:
	CLASSDEF(Eload_tool); 
	Emachining_toolPtr its_tool; 
};
class Eunload_tool :
	public  Enc_function
{
public:
	CLASSDEF(Eunload_tool); 
	Emachining_toolPtr its_tool; 
};
class Etool_direction_for_milling :
	public  Etool_direction
{
public:
	CLASSDEF(Etool_direction_for_milling); 
};
class Ethree_axes_tilted_tool :
	public  Etool_direction_for_milling
{
public:
	CLASSDEF(Ethree_axes_tilted_tool); 
	EdirectionPtr tool_direction; 
};
class Efive_axes_var_tilt_yaw :
	public  Etool_direction_for_milling
{
public:
	CLASSDEF(Efive_axes_var_tilt_yaw); 
};
class Efive_axes_const_tilt_yaw :
	public  Etool_direction_for_milling
{
public:
	CLASSDEF(Efive_axes_const_tilt_yaw); 
	Eplane_angle_measurePtr tilt_angle; 
	Eplane_angle_measurePtr yaw_angle; 
};
class Emilling_machining_operation :
	public  Emachining_operation
{
public:
	CLASSDEF(Emilling_machining_operation); 
	Elength_measurePtr overcut_length; 
};
class Emilling_technology :
	public  Etechnology
{
public:
	CLASSDEF(Emilling_technology); 
	Espeed_measurePtr cutspeed; 
	Erot_speed_measurePtr spindle; 
	Elength_measurePtr feedrate_per_tooth; 
	EBooleanPtr synchronize_spindle_with_feed; 
	EBooleanPtr inhibit_feedrate_override; 
	EBooleanPtr inhibit_spindle_override; 
	Eadaptive_controlPtr its_adaptive_control; 
};
class Eadaptive_control :
		public IStepNode
{
public:
	CLASSDEF(Eadaptive_control); 
};
class Emilling_machine_functions :
	public  Emachine_functions
{
public:
	CLASSDEF(Emilling_machine_functions); 
	EBooleanPtr coolant; 
	Epressure_measurePtr coolant_pressure; 
	EBooleanPtr mist; 
	EBooleanPtr through_spindle_coolant; 
	Epressure_measurePtr through_pressure; 
	EListT<EidentifierPtr> axis_clamping; 
	EBooleanPtr chip_removal; 
	EdirectionPtr oriented_spindle_stop; 
	Eprocess_model_listPtr its_process_model; 
	EListT<Eproperty_parameterPtr> other_functions; 
};
class Eprocess_model_list :
		public IStepNode
{
public:
	CLASSDEF(Eprocess_model_list); 
	EListT<Eprocess_modelPtr> its_list; 
};
class Eprocess_model :
		public IStepNode
{
public:
	CLASSDEF(Eprocess_model); 
	ElabelPtr ini_data_file; 
	ElabelPtr its_type; 
};
class Emilling_type_operation :
	public  Emilling_machining_operation
{
public:
	CLASSDEF(Emilling_type_operation); 
	Eapproach_retract_strategyPtr approach; 
	Eapproach_retract_strategyPtr retract; 
};
class Eapproach_retract_strategy :
		public IStepNode
{
public:
	CLASSDEF(Eapproach_retract_strategy); 
	EdirectionPtr tool_orientation; 
};
class Eplunge_strategy :
	public  Eapproach_retract_strategy
{
public:
	CLASSDEF(Eplunge_strategy); 
};
class Eplunge_toolaxis :
	public  Eplunge_strategy
{
public:
	CLASSDEF(Eplunge_toolaxis); 
};
class Eplunge_ramp :
	public  Eplunge_strategy
{
public:
	CLASSDEF(Eplunge_ramp); 
	Eplane_angle_measurePtr angle; 
};
class Eplunge_helix :
	public  Eplunge_strategy
{
public:
	CLASSDEF(Eplunge_helix); 
	Elength_measurePtr radius; 
	Eplane_angle_measurePtr angle; 
};
class Eplunge_zigzag :
	public  Eplunge_strategy
{
public:
	CLASSDEF(Eplunge_zigzag); 
	Eplane_angle_measurePtr angle; 
	Elength_measurePtr width; 
};
class Eair_strategy :
	public  Eapproach_retract_strategy
{
public:
	CLASSDEF(Eair_strategy); 
};
class Eap_retract_angle :
	public  Eair_strategy
{
public:
	CLASSDEF(Eap_retract_angle); 
	Eplane_angle_measurePtr angle; 
	Elength_measurePtr travel_length; 
};
class Eap_retract_tangent :
	public  Eair_strategy
{
public:
	CLASSDEF(Eap_retract_tangent); 
	Elength_measurePtr radius; 
};
class Ealong_path :
	public  Eapproach_retract_strategy
{
public:
	CLASSDEF(Ealong_path); 
	Etoolpath_listPtr path; 
};
class Efreeform_operation :
	public  Emilling_type_operation
{
public:
	CLASSDEF(Efreeform_operation); 
	Efreeform_strategyPtr its_machining_strategy; 
};
class Efreeform_strategy :
		public IStepNode
{
public:
	CLASSDEF(Efreeform_strategy); 
	Epathmode_typePtr pathmode; 
	Ecutmode_typePtr cutmode; 
	EtolerancesPtr its_milling_tolerances; 
	Elength_measurePtr stepover; 
};
class Etolerances :
		public IStepNode
{
public:
	CLASSDEF(Etolerances); 
	Elength_measurePtr chordal_tolerance; 
	Elength_measurePtr scallop_height; 
};
class Euv_strategy :
	public  Efreeform_strategy
{
public:
	CLASSDEF(Euv_strategy); 
	EdirectionPtr forward_direction; 
	EdirectionPtr sideward_direction; 
};
class Eplane_cc_strategy :
	public  Efreeform_strategy
{
public:
	CLASSDEF(Eplane_cc_strategy); 
	EdirectionPtr its_plane_normal; 
};
class Eplane_cl_strategy :
	public  Efreeform_strategy
{
public:
	CLASSDEF(Eplane_cl_strategy); 
	EdirectionPtr its_plane_normal; 
};
class Eleading_line_strategy :
	public  Efreeform_strategy
{
public:
	CLASSDEF(Eleading_line_strategy); 
	Ebounded_curvePtr its_line; 
};
class Etwo5d_milling_operation :
	public  Emilling_type_operation
{
public:
	CLASSDEF(Etwo5d_milling_operation); 
	Etwo5d_milling_strategyPtr its_machining_strategy; 
};
class Etwo5d_milling_strategy :
		public IStepNode
{
public:
	CLASSDEF(Etwo5d_milling_strategy); 
	Epositive_ratio_measurePtr overlap; 
	EBooleanPtr allow_multiple_passes; 
};
class Eunidirectional :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Eunidirectional); 
	EdirectionPtr feed_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ebidirectional :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Ebidirectional); 
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Estroke_connection_strategyPtr its_stroke_connection_strategy; 
};
class Econtour_parallel :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Econtour_parallel); 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ebidirectional_contour :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Ebidirectional_contour); 
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr spiral_cutmode; 
};
class Econtour_bidirectional :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Econtour_bidirectional); 
	EdirectionPtr feed_direction; 
	Eleft_or_rightPtr stepover_direction; 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr spiral_cutmode; 
};
class Econtour_spiral :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Econtour_spiral); 
	Erot_directionPtr rotation_direction; 
	Ecutmode_typePtr cutmode; 
};
class Ecenter_milling :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Ecenter_milling); 
};
class Eexplicit :
	public  Etwo5d_milling_strategy
{
public:
	CLASSDEF(Eexplicit); 
};
class Eplane_milling :
	public  Etwo5d_milling_operation
{
public:
	CLASSDEF(Eplane_milling); 
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr allowance_bottom; 
};
class Eplane_rough_milling :
	public  Eplane_milling
{
public:
	CLASSDEF(Eplane_rough_milling); 
};
class Eplane_finish_milling :
	public  Eplane_milling
{
public:
	CLASSDEF(Eplane_finish_milling); 
};
class Eside_milling :
	public  Etwo5d_milling_operation
{
public:
	CLASSDEF(Eside_milling); 
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr radial_cutting_depth; 
	Elength_measurePtr allowance_side; 
};
class Eside_rough_milling :
	public  Eside_milling
{
public:
	CLASSDEF(Eside_rough_milling); 
};
class Eside_finish_milling :
	public  Eside_milling
{
public:
	CLASSDEF(Eside_finish_milling); 
};
class Ebottom_and_side_milling :
	public  Etwo5d_milling_operation
{
public:
	CLASSDEF(Ebottom_and_side_milling); 
	Elength_measurePtr axial_cutting_depth; 
	Elength_measurePtr radial_cutting_depth; 
	Elength_measurePtr allowance_side; 
	Elength_measurePtr allowance_bottom; 
};
class Ebottom_and_side_rough_milling :
	public  Ebottom_and_side_milling
{
public:
	CLASSDEF(Ebottom_and_side_rough_milling); 
};
class Ebottom_and_side_finish_milling :
	public  Ebottom_and_side_milling
{
public:
	CLASSDEF(Ebottom_and_side_finish_milling); 
};
class Edrilling_type_operation :
	public  Emilling_machining_operation
{
public:
	CLASSDEF(Edrilling_type_operation); 
	Elength_measurePtr cutting_depth; 
	Elength_measurePtr previous_diameter; 
	Etime_measurePtr dwell_time_bottom; 
	Epositive_ratio_measurePtr feed_on_retract; 
	Edrilling_type_strategyPtr its_machining_strategy; 
};
class Edrilling_type_strategy :
		public IStepNode
{
public:
	CLASSDEF(Edrilling_type_strategy); 
	Epositive_ratio_measurePtr reduced_cut_at_start; 
	Epositive_ratio_measurePtr reduced_feed_at_start; 
	Elength_measurePtr depth_of_start; 
	Epositive_ratio_measurePtr reduced_cut_at_end; 
	Epositive_ratio_measurePtr reduced_feed_at_end; 
	Elength_measurePtr depth_of_end; 
};
class Edrilling_operation :
	public  Edrilling_type_operation
{
public:
	CLASSDEF(Edrilling_operation); 
};
class Edrilling :
	public  Edrilling_operation
{
public:
	CLASSDEF(Edrilling); 
};
class Ecenter_drilling :
	public  Edrilling_operation
{
public:
	CLASSDEF(Ecenter_drilling); 
};
class Ecounter_sinking :
	public  Edrilling_operation
{
public:
	CLASSDEF(Ecounter_sinking); 
};
class Emultistep_drilling :
	public  Edrilling_operation
{
public:
	CLASSDEF(Emultistep_drilling); 
	Elength_measurePtr retract_distance; 
	Elength_measurePtr first_depth; 
	Elength_measurePtr depth_of_step; 
	Etime_measurePtr dwell_time_step; 
};
class Eboring_operation :
	public  Edrilling_type_operation
{
public:
	CLASSDEF(Eboring_operation); 
	EBooleanPtr spindle_stop_at_bottom; 
	Elength_measurePtr depth_of_testcut; 
	Ecartesian_pointPtr waiting_position; 
};
class Eboring :
	public  Eboring_operation
{
public:
	CLASSDEF(Eboring); 
};
class Ereaming :
	public  Eboring_operation
{
public:
	CLASSDEF(Ereaming); 
};
class Eback_boring :
	public  Edrilling_type_operation
{
public:
	CLASSDEF(Eback_boring); 
};
class Etapping :
	public  Edrilling_type_operation
{
public:
	CLASSDEF(Etapping); 
	EBooleanPtr compensation_chuck; 
};
class Ethread_drilling :
	public  Edrilling_type_operation
{
public:
	CLASSDEF(Ethread_drilling); 
	EBooleanPtr helical_movement_on_forward; 
};
class Eday_in_month_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eday_in_month_number); 
};
class Emonth_in_year_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Emonth_in_year_number); 
};
class Eday_in_year_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eday_in_year_number); 
};
class Eweek_in_year_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eweek_in_year_number); 
};
class Eday_in_week_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eday_in_week_number); 
};
class Ehour_in_day : public EInteger /*typedef*/
{
public:
	CLASSDEF(Ehour_in_day); 
};
class Eminute_in_hour : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eminute_in_hour); 
};
class Esecond_in_minute : public EReal /*typedef*/
{
public:
	CLASSDEF(Esecond_in_minute); 
};
class Eahead_or_behind : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Eahead_or_behind); 
	enum Eahead_or_behindEnum
	{
	ahead=0,
	exact,
	behind} ;
	void SetSelection(Eahead_or_behindEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static char * szEnums[3]={
"ahead",
"exact",
"behind"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eyear_number : public EInteger /*typedef*/
{
public:
	CLASSDEF(Eyear_number); 
};
class Eidentifier : public EString /*typedef*/
{
public:
	CLASSDEF(Eidentifier); 
};
class Elabel : public EString /*typedef*/
{
public:
	CLASSDEF(Elabel); 
};
class Etext : public EString /*typedef*/
{
public:
	CLASSDEF(Etext); 
};
class Elength_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Elength_measure); 
};
class Eparameter_value : public EReal /*typedef*/
{
public:
	CLASSDEF(Eparameter_value); 
};
class Eplane_angle_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Eplane_angle_measure); 
};
class Epositive_length_measure : public Elength_measure /*typedef*/
{
public:
	CLASSDEF(Epositive_length_measure); 
};
class Eratio_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Eratio_measure); 
};
class Epositive_ratio_measure : public Eratio_measure /*typedef*/
{
public:
	CLASSDEF(Epositive_ratio_measure); 
};
class Etime_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Etime_measure); 
};
class Etrimming_select : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Etrimming_select); 
	Ecartesian_pointPtr _Ecartesian_point;
	Eparameter_valuePtr _Eparameter_value;
};
class Etrimming_preference : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Etrimming_preference); 
	enum Etrimming_preferenceEnum
	{
	cartesian=0,
	parameter,
	unspecified} ;
	void SetSelection(Etrimming_preferenceEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static char * szEnums[3]={
"cartesian",
"parameter",
"unspecified"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Etransition_code : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Etransition_code); 
	enum Etransition_codeEnum
	{
	discontinuous=0,
	continuous,
	cont_same_gradient,
	cont_same_gradient_same_curvature} ;
	void SetSelection(Etransition_codeEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 4;
		static char * szEnums[4]={
"discontinuous",
"continuous",
"cont_same_gradient",
"cont_same_gradient_same_curvature"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 4;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eb_spline_curve_form : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Eb_spline_curve_form); 
	enum Eb_spline_curve_formEnum
	{
	polyline_form=0,
	circular_arc,
	elliptic_arc,
	parabolic_arc,
	hyperbolic_arc,
	unspecified} ;
	void SetSelection(Eb_spline_curve_formEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 6;
		static char * szEnums[6]={
"polyline_form",
"circular_arc",
"elliptic_arc",
"parabolic_arc",
"hyperbolic_arc",
"unspecified"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 6;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eb_spline_surface_form : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Eb_spline_surface_form); 
	enum Eb_spline_surface_formEnum
	{
	plane_surf=0,
	cylindrical_surf,
	conical_surf,
	spherical_surf,
	toroidal_surf,
	surf_of_revolution,
	ruled_surf,
	generalised_cone,
	quadric_surf,
	surf_of_linear_extrusion,
	unspecified} ;
	void SetSelection(Eb_spline_surface_formEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 11;
		static char * szEnums[11]={
"plane_surf",
"cylindrical_surf",
"conical_surf",
"spherical_surf",
"toroidal_surf",
"surf_of_revolution",
"ruled_surf",
"generalised_cone",
"quadric_surf",
"surf_of_linear_extrusion",
"unspecified"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 11;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Edimension_count : public EInteger /*typedef*/
{
public:
	CLASSDEF(Edimension_count); 
};
class Eknot_type : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Eknot_type); 
	enum Eknot_typeEnum
	{
	uniform_knots=0,
	quasi_uniform_knots,
	piecewise_bezier_knots,
	unspecified} ;
	void SetSelection(Eknot_typeEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 4;
		static char * szEnums[4]={
"uniform_knots",
"quasi_uniform_knots",
"piecewise_bezier_knots",
"unspecified"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 4;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Epcurve_or_surface : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Epcurve_or_surface); 
	EpcurvePtr _Epcurve;
	EsurfacePtr _Esurface;
};
class Evector_or_direction : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Evector_or_direction); 
	EvectorPtr _Evector;
	EdirectionPtr _Edirection;
};
class Etolerance_select : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Etolerance_select); 
	Eplus_minus_valuePtr _Eplus_minus_value;
	Elimits_and_fitsPtr _Elimits_and_fits;
};
class Efitting_type : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Efitting_type); 
	enum Efitting_typeEnum
	{
	shaft=0,
	hole} ;
	void SetSelection(Efitting_typeEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static char * szEnums[2]={
"shaft",
"hole"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Espeed_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Espeed_measure); 
};
class Erot_speed_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Erot_speed_measure); 
};
class Epressure_measure : public EReal /*typedef*/
{
public:
	CLASSDEF(Epressure_measure); 
};
class Erot_direction : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Erot_direction); 
	enum Erot_directionEnum
	{
	cw=0,
	ccw} ;
	void SetSelection(Erot_directionEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static char * szEnums[2]={
"cw",
"ccw"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eshape_tolerance : public Elength_measure /*typedef*/
{
public:
	CLASSDEF(Eshape_tolerance); 
};
class Ebounding_geometry_select : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Ebounding_geometry_select); 
	EblockPtr _Eblock;
	Eright_circular_cylinderPtr _Eright_circular_cylinder;
	Eadvanced_brep_shape_representationPtr _Eadvanced_brep_shape_representation;
};
class Eprofile_select : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Eprofile_select); 
	Ethrough_profile_floorPtr _Ethrough_profile_floor;
	Eprofile_floorPtr _Eprofile_floor;
};
class Etaper_select : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Etaper_select); 
	Ediameter_taperPtr _Ediameter_taper;
	Eangle_taperPtr _Eangle_taper;
};
class Ecompound_feature_select : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Ecompound_feature_select); 
	Emachining_featurePtr _Emachining_feature;
	Etransition_featurePtr _Etransition_feature;
};
class Ebottom_or_side : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Ebottom_or_side); 
	enum Ebottom_or_sideEnum
	{
	bottom=0,
	side,
	bottom_and_side} ;
	void SetSelection(Ebottom_or_sideEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static char * szEnums[3]={
"bottom",
"side",
"bottom_and_side"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Erestricted_area_select : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Erestricted_area_select); 
	Ebounded_surfacePtr _Ebounded_surface;
	Ebounding_geometry_selectPtr _Ebounding_geometry_select;
};
class Ervalue : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Ervalue); 
	Enc_constantPtr _Enc_constant;
	Enc_variablePtr _Enc_variable;
};
class Etool_reference_point : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Etool_reference_point); 
	enum Etool_reference_pointEnum
	{
	tcp=0,
	ccp} ;
	void SetSelection(Etool_reference_pointEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static char * szEnums[2]={
"tcp",
"ccp"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Etoolpath_type : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Etoolpath_type); 
	enum Etoolpath_typeEnum
	{
	approach=0,
	lift,
	connect,
	non_contact,
	contact,
	trajectory_path} ;
	void SetSelection(Etoolpath_typeEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 6;
		static char * szEnums[6]={
"approach",
"lift",
"connect",
"non_contact",
"contact",
"trajectory_path"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 6;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Etoolpath_speedprofile : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Etoolpath_speedprofile); 
	Etoolpath_speedPtr _Etoolpath_speed;
	Epositive_ratio_measurePtr _Epositive_ratio_measure;
	Espeed_namePtr _Espeed_name;
};
class Espeed_name : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Espeed_name); 
	enum Espeed_nameEnum
	{
	RAPID=0} ;
	void SetSelection(Espeed_nameEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 1;
		static char * szEnums[1]={
"RAPID"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 1;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Ecurve_with_surface_normal : /*select headache*/ 
	public ESelection
{
public:
	CLASSDEF(Ecurve_with_surface_normal); 
	Ebounded_pcurvePtr _Ebounded_pcurve;
	Ecurve_with_normal_vectorPtr _Ecurve_with_normal_vector;
};
class Econtact_type : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Econtact_type); 
	enum Econtact_typeEnum
	{
	side=0,
	front} ;
	void SetSelection(Econtact_typeEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static char * szEnums[2]={
"side",
"front"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Ehand : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Ehand); 
	enum EhandEnum
	{
	left=0,
	right,
	neutral} ;
	void SetSelection(EhandEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 3;
		static char * szEnums[3]={
"left",
"right",
"neutral"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 3;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Epathmode_type : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Epathmode_type); 
	enum Epathmode_typeEnum
	{
	forward=0,
	zigzag} ;
	void SetSelection(Epathmode_typeEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static char * szEnums[2]={
"forward",
"zigzag"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Ecutmode_type : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Ecutmode_type); 
	enum Ecutmode_typeEnum
	{
	climb=0,
	conventional} ;
	void SetSelection(Ecutmode_typeEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static char * szEnums[2]={
"climb",
"conventional"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Eleft_or_right : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Eleft_or_right); 
	enum Eleft_or_rightEnum
	{
	left=0,
	right} ;
	void SetSelection(Eleft_or_rightEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static char * szEnums[2]={
"left",
"right"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 2;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
class Estroke_connection_strategy : /*select headache*/ 
	public EEnum
{
public:
	CLASSDEF(Estroke_connection_strategy); 
	enum Estroke_connection_strategyEnum
	{
	straghtline=0,
	lift_shift_plunge,
	degouge,
	loop_back} ;
	void SetSelection(Estroke_connection_strategyEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 4;
		static char * szEnums[4]={
"straghtline",
"lift_shift_plunge",
"degouge",
"loop_back"};
	if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) {
		szEnum.MakeLower();
		static int nEnums = 4;		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
	}
		return 0;
	}
};
} /* End namespace Express*/
