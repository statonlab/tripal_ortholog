<?php
/**
 * @class
 * Purpose:
 *
 * Data:
 * Assumptions:
 */
class so__sequence_collection extends ChadoField {

  // --------------------------------------------------------------------------
  //                     EDITABLE STATIC CONSTANTS
  //
  // The following constants SHOULD be set for each descendant class.  They are
  // used by the static functions to provide information to Drupal about
  // the field and it's default widget and formatter.
  // --------------------------------------------------------------------------

  // The default label for this field.
  public static $default_label = 'Orthologs';

  // The default description for this field.
  public static $default_description = 'Displays the orthologous group and associated features';

  // The default widget for this field.
  public static $default_widget = 'so__sequence_collection_widget';

  // The default formatter for this field.
  public static $default_formatter = 'so__sequence_collection_formatter';

  // The module that manages this field.
  // If no module manages the field (IE it's added via libraries)
  // set this to 'tripal_chado'
  public static $module = 'tripal_ortholog';

  // A list of global settings. These can be accessed within the
  // globalSettingsForm.  When the globalSettingsForm is submitted then
  // Drupal will automatically change these settings for all fields.
  // Once instances exist for a field type then these settings cannot be
  // changed.
  public static $default_settings = array(
    'storage' => 'field_chado_storage',
     // It is expected that all fields set a 'value' in the load() function.
     // In many cases, the value may be an associative array of key/value pairs.
     // In order for Tripal to provide context for all data, the keys should
     // be a controlled vocabulary term (e.g. rdfs:type). Keys in the load()
     // function that are supported by the query() function should be
     // listed here.
     'searchable_keys' => array(),
  );

  // Provide a list of instance specific settings. These can be access within
  // the instanceSettingsForm.  When the instanceSettingsForm is submitted
  // then Drupal with automatically change these settings for the instance.
  // It is recommended to put settings at the instance level whenever possible.
  // If you override this variable in a child class be sure to replicate the
  // term_name, term_vocab, term_accession and term_fixed keys as these are
  // required for all TripalFields.
  public static $default_instance_settings = array(
    // The DATABASE name, as it appears in chado.db.  This also builds the link-out url.  In most cases this will simply be the CV name.  In some cases (EDAM) this will be the SUBONTOLOGY.
    'term_vocabulary' => 'SO',
    // The name of the term.
    'term_name' => 'sequence_collection',
    // The unique ID (i.e. accession) of the term.
    'term_accession' => '0001260',
    // Set to TRUE if the site admin is not allowed to change the term
    // type, otherwise the admin can change the term mapped to a field.
    'term_fixed' => FALSE,
    // Indicates if this field should be automatically attached to display
    // or web services or if this field should be loaded separately. This
    // is convenient for speed.  Fields that are slow should for loading
    // should have auto_attach set to FALSE so tha their values can be
    // attached asynchronously.
    'auto_attach' => FALSE,
    // The table in Chado that the instance maps to.
  //  'chado_table' => 'grp',
    // The column of the table in Chado where the value of the field comes from.
  //  'chado_column' => 'grp_id',
    // The base table.
  //  'base_table' => 'grp',
     // Indicates the download formats for this field.  The list must be the
    // name of a child class of the TripalFieldDownloader.
    'download_formatters' => array(
      'TripalTabDownloader',
      'TripalCSVDownloader',
    ),
  );

  // A boolean specifying that users should not be allowed to create
  // fields and instances of this field type through the UI. Such
  // fields can only be created programmatically with field_create_field()
  // and field_create_instance().
  public static $no_ui = FALSE;

  // A boolean specifying that the field will not contain any data. This
  // should exclude the field from web services or downloads.  An example
  // could be a quick search field that appears on the page that redirects
  // the user but otherwise provides no data.
  public static $no_data = FALSE;

 /**
   * Loads the field values from the underlying data store.
   *
   * @param $entity
   *
   * @return
   *   An array of the following format:
   *     $entity->{$field_name}['und'][0]['value'] = $value;
   *   where:
   *     - $entity is the entity object to which this field is attached.
   *     - $field_name is the name of this field
   *     - 'und' is the language code (in this case 'und' == undefined)
   *     - 0 is the cardinality.  Increment by 1 when more than one item is
   *       available.
   *     - 'value' is the key indicating the value of this field. It should
   *       always be set.  The value of the 'value' key will be the contents
   *       used for web services and for downloadable content.  The value
   *       should be of the follow format types: 1) A single value (text,
   *       numeric, etc.) 2) An array of key value pair. 3) If multiple entries
   *       then cardinality should incremented and format types 1 and 2 should
   *       be used for each item.
   *   The array may contain as many other keys at the same level as 'value'
   *   but those keys are for internal field use and are not considered the
   *   value of the field.
   *
   *
   */
  public function load($entity) {


    parent::load($entity);

    //Given that the entity is a feature, look if this feature is a grpmember, in feature_grpmember.
    //Then look up the grp.
    //get info on that group.
    //Then retrieve all other group members that are a part of each group.
    //Finally return, organized by group, the list of groupmembers and the group info.


  }



  /**
   * Used to filter records that match a given condition.
   *
   * Records that belong to a content type can be filtered using the fields.
   * This function should be implemented if the field  supports filtering as
   * specified in the elementInfo() function.  With this function, the query
   * object appropriate for the storage back-end is passed into the function.
   *
   * The condition array passesd in will have three values:
   *   - column:  the key indicating how the filter should occur.
   *   - op: the operation to perform (e.g. equals, contains, starts with etc.
   *   - value:  the value for filtering.
   *
   * The column used for filtering will be a comma-speperated list of
   * controlled vocabulary IDs. This comma-separate list corresponds directly
   * to the heirarchy of elements provided by the elementInfo() function.
   * For example, if a field provides organism information then it may use
   * the OBI:0100026 term for the field, and the term TAXRANK:0000005 for the
   * term to indicate the 'Genus'.  If these fields are properly organized in
   * the elementInfo() function then the "column" of the condition when
   * a user wants to search by genus will be: OBI:0100026,TAXRANK:0000005.
   *
   * @param $query
   *   A query object appropriate for the data storage backend. For example,
   *   The Tripal Chado module will provide a SelectQuery object.
   * @param $condition
   *   The field specific condition as set in the TripalFieldQuery object.
   *
   * In addition to the rules to follow for the TripalField::query function
   * these should also be followed for the ChadoField::query implementation.
   *
   * - When giving alias to joined tables be sure to use aliases that are
   *   unique to avoid conflicts with other fields.
   * - When joining with the base table its alias is 'base'.
   * - You may join to materialized views if need be to help speed queries.
   */
  public function query($query, $condition) {
  }

  /**
   * Used to sort records that have been filtered.
   *
   * @param $query
   *   A query object appropriate for the data storage backend. For example,
   *   The Tripal Chado module will provide a SelectQuery object.
   * @param $order
   *   The field ordering as set in the TripalFieldQuery object.  This function
   *   should handle the ordering request as specified by this object.
   */

  public function queryOrder($query, $order) {
  }


  /**
   * Provides the list of elements returned by the 'value' of the field.
   *
   * The elements provided by this function are used to integrate with
   * Drupal Views and Web services.  The return value is an associative array
   * that contains all of the elements that will be returned by the
   * 'value' of this field. If the value field returns an element which
   * is not defined here a warning will be generated.
   *
   * The array structure should contain at the top-level a key of the form
   * {db}:{accession}. This represents the term that this field belongs to.
   * The value of this top-level key is an array with the following keys:
   *   -name: this key is not actually used but is availble to improve
   *     readability of the array.  Because the key is a vocabulary term
   *     conaining only the accession it's not always clear what it means.
   *     Providing a 'name' key helps other's know what the term is.
   *   -searchable:  TRUE if the element can be used for filtering the content
   *     type to which tis field is attached.  FALSE if not.
   *   -operations:  an array of filtering operations that can be used for this
   *     field.  These include: 'eq', 'ne', 'contains', 'starts', 'gt', 'lt',
   *     'gte', 'lte'.  These opertaions are applicable to strings: 'eq', 'ne',
   *     'contains', and 'starts'.  These operations are applicable for numeric
   *     values: 'gt', 'lt', 'gte', 'lte'.
   *   -label: The label (if applicable) to appear for the elmeent. The default
   *     is to use the term's name.
   *   -help: Help text (if applicable) to appear for the element. The default
   *     is to use the term's definition.
   *   -type: The data type: e.g. 'string' or 'numeric'. Default is 'string'.
   *   -sortable: TRUE if the element can be sorted.  FALSE if not.
   *   -elements:  If this field value is a simple scalar (i.e. string or
   *     number) then this key is not needed. But, if the 'value' of the
   *     field is an array with sub keys then those subkeys must be defined
   *     using this key.  The members of the element array follows the same
   *     format as the top-level key and the above subkeys can be used as well.
   *
   * The following code provides an example for describing the value elements
   * of this field.  The Tripal Chado module provides an obi__organism field
   * that attaches organism details to content types such as genes, mRNA,
   * stocks, etc.  It provides a label containing the full scientific name of
   * the organism as well as the genus, species, infraspecific name,
   * and infraspecific type. If the organism to which the field belong is
   * published then an entity ID is provided.  The following array describes
   * all of these.
   * @code
    $field_term = $this->getFieldTermID();
    return array(
      $field_term => array(
        'operations' => array('eq', 'contains', 'starts'),
        'sortable' => TRUE,
        'searchable' => TRUE,
        'elements' => array(
          'rdfs:label' => array(
            'searchable' => TRUE,
            'name' => 'scientific_name',
            'operations' => array('eq', 'ne', 'contains', 'starts'),
            'sortable' => TRUE,
          ),
          'TAXRANK:0000005' => array(
            'searchable' => TRUE,
            'name' => 'genus',
            'operations' => array('eq', 'ne', 'contains', 'starts'),
            'sortable' => TRUE,
          ),
          'TAXRANK:0000006' => array(
            'searchable' => TRUE,
            'name' => 'species',
            'operations' => array('eq', 'ne', 'contains', 'starts'),
            'sortable' => TRUE,
          ),
          'TAXRANK:0000045' => array(
            'searchable' => TRUE,
            'name' => 'infraspecies',
            'operations' => array('eq', 'ne', 'contains', 'starts'),
            'sortable' => TRUE,
          ),
          'local:infraspecific_type' => array(
            'searchable' => TRUE,
            'name' => 'infraspecific_type',
            'operations' => array('eq', 'ne', 'contains', 'starts'),
            'sortable' => TRUE,
          ),
          'entity' => array(
            'searchable' => FALSE,
          ),
        ),
      )
    );
   * @endcode
   *
   * If a field does not have a complex nested set of values, but simply returns
   * a scalar then the default elementInfo provides default string-based
   * searchabilty.
   *
   * @return
   *   An associative array of the value elements provided by this field.
   */
  public function elementInfo() {
    $field_term = $this->getFieldTermID();
    return array(
      $field_term => array(
        'operations' => array('eq', 'ne', 'contains', 'starts'),
        'sortable' => TRUE,
        'searchable' => TRUE,
      ),
    );
  }

}


