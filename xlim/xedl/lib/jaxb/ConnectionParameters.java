//
// This file was generated by the JavaTM Architecture for XML Binding(JAXB) Reference Implementation, v2.1.2-b01-fcs 
// See <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// Any modifications to this file will be lost upon recompilation of the source schema. 
// Generated on: 2007.02.14 at 02:11:19 PM CET 
//


package xedl.lib.jaxb;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for anonymous complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType>
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;choice>
 *           &lt;element name="BANDWIDTH" type="{http://www.w3.org/2001/XMLSchema}int"/>
 *           &lt;element ref="{}upanddownbandwidth"/>
 *         &lt;/choice>
 *         &lt;element name="PROTECTION" type="{}protection_type" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "", propOrder = {
    "bandwidth",
    "upanddownbandwidth",
    "protection"
})
@XmlRootElement(name = "connection-parameters")
public class ConnectionParameters {

    @XmlElement(name = "BANDWIDTH")
    protected Integer bandwidth;
    protected Upanddownbandwidth upanddownbandwidth;
    @XmlElement(name = "PROTECTION")
    protected ProtectionType protection;

    /**
     * Gets the value of the bandwidth property.
     * 
     * @return
     *     possible object is
     *     {@link Integer }
     *     
     */
    public Integer getBANDWIDTH() {
        return bandwidth;
    }

    /**
     * Sets the value of the bandwidth property.
     * 
     * @param value
     *     allowed object is
     *     {@link Integer }
     *     
     */
    public void setBANDWIDTH(Integer value) {
        this.bandwidth = value;
    }

    /**
     * Gets the value of the upanddownbandwidth property.
     * 
     * @return
     *     possible object is
     *     {@link Upanddownbandwidth }
     *     
     */
    public Upanddownbandwidth getUpanddownbandwidth() {
        return upanddownbandwidth;
    }

    /**
     * Sets the value of the upanddownbandwidth property.
     * 
     * @param value
     *     allowed object is
     *     {@link Upanddownbandwidth }
     *     
     */
    public void setUpanddownbandwidth(Upanddownbandwidth value) {
        this.upanddownbandwidth = value;
    }

    /**
     * Gets the value of the protection property.
     * 
     * @return
     *     possible object is
     *     {@link ProtectionType }
     *     
     */
    public ProtectionType getPROTECTION() {
        return protection;
    }

    /**
     * Sets the value of the protection property.
     * 
     * @param value
     *     allowed object is
     *     {@link ProtectionType }
     *     
     */
    public void setPROTECTION(ProtectionType value) {
        this.protection = value;
    }

}
